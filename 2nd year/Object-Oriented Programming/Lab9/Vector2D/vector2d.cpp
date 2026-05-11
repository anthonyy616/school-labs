#include "vector2d.h"
#include <stdexcept>

Vector2D::Vector2D() : x(0.0), y(0.0) {}

Vector2D::Vector2D(double xVal, double yVal) : x(xVal), y(yVal) {}

void Vector2D::display() const { std::cout << "(" << x << ", " << y << ")"; }

Vector2D Vector2D::operator+(const Vector2D &other) const {
  return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D &other) const {
  return Vector2D(x - other.x, y - other.y);
}

bool Vector2D::operator==(const Vector2D &other) const {
  return x == other.x && y == other.y;
}

bool Vector2D::operator!=(const Vector2D &other) const {
  return !(*this == other);
}

double &Vector2D::operator[](int index) {
  if (index == 0)
    return x;
  if (index == 1)
    return y;
  throw std::out_of_range("Index out of bounds. Use 0 for x, 1 for y.");
}

const double &Vector2D::operator[](int index) const {
  if (index == 0)
    return x;
  if (index == 1)
    return y;
  throw std::out_of_range("Index out of bounds. Use 0 for x, 1 for y.");
}

std::ostream &operator<<(std::ostream &os, const Vector2D &v) {
  os << "(" << v.x << ", " << v.y << ")";
  return os;
}

std::istream &operator>>(std::istream &is, Vector2D &v) {
  is >> v.x >> v.y;
  return is;
}