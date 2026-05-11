#include "integer.h"
#include "vector2d.h"
#include <iostream>


int main() {
  std::cout << "=== Task 1: Integer Class ===\n";

  Integer a(10);
  Integer b(5);
  Integer c;

  std::cout << "a = " << a << ", b = " << b << "\n";
  c = a + b;
  std::cout << "a + b = " << c << "\n";

  c = a - b;
  std::cout << "a - b = " << c << "\n";

  std::cout << "a == b: " << (a == b ? "true" : "false") << "\n";
  std::cout << "a != b: " << (a != b ? "true" : "false") << "\n";

  std::cout << "Pre-increment a: " << ++a << "\n";
  std::cout << "Post-increment b: " << b++ << " (now b = " << b << ")\n";

  std::cout << "\n=== Task 2: Vector2D Class ===\n";

  Vector2D v1(2.5, 3.0);
  Vector2D v2(1.0, -1.5);
  Vector2D v3;

  std::cout << "v1 = " << v1 << ", v2 = " << v2 << "\n";

  v3 = v1 + v2;
  std::cout << "v1 + v2 = " << v3 << "\n";

  v3 = v1 - v2;
  std::cout << "v1 - v2 = " << v3 << "\n";

  std::cout << "v1 == v2: " << (v1 == v2 ? "true" : "false") << "\n";

  std::cout << "v1[0] = " << v1[0] << ", v1[1] = " << v1[1] << "\n";

  // Test bounds checking (uncomment to test)
  // std::cout << v1[2] << "\n";

  // Stream input example
  std::cout << "\nEnter a vector (x y): ";
  std::cin >> v3;
  std::cout << "You entered: " << v3 << "\n";

  std::cout << "\nAll tests completed successfully!\n";
  return 0;
}