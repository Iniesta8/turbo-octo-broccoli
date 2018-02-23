#include <iostream>
#include <vector>

struct Vertex
{
  int x, y, z;
  
  Vertex(int x, int y, int z)
    : x(x), y(y), z(z) {}

  Vertex(const Vertex& other)
    : x(other.x), y(other.y), z(other.z)
  {
    std::cout << "Copied a vertex" << std::endl;
  }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
  stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
  return stream;
}

int main(void)
{
  std::cout << "First try: bad solution..." << std::endl; 
  std::vector<Vertex> vertices1;

  vertices1.push_back(Vertex(1, 2, 3));
  vertices1.push_back(Vertex(4, 5, 6));
  vertices1.push_back(Vertex(7, 8, 9));
  std::cout << "Adding three vertices causes 6 copies!" << std::endl;
  
  std::cout << "Second try: use reserve to rerserve memory for three vertices" << std::endl; 
  std::vector<Vertex> vertices2;
  vertices2.reserve(3);

  vertices2.push_back(Vertex(1, 2, 3));
  vertices2.push_back(Vertex(4, 5, 6));
  vertices2.push_back(Vertex(7, 8, 9));
  std::cout << "Adding three vertices now causes 3 copies!" << std::endl;

  std::cout << "Third try: use reserve to rerserve memory for three vertices and emplace_back() to add the vertices" << std::endl; 
  std::vector<Vertex> vertices3;
  vertices3.reserve(3);

  vertices3.emplace_back(1, 2, 3);
  vertices3.emplace_back(4, 5, 6);
  vertices3.emplace_back(7, 8, 9);
  std::cout << "Adding three vertices now causes 0 copies! That's the way to do it!" << std::endl;
  
  vertices1.clear();
  vertices2.clear();
  vertices3.clear();

  return 0;
}
