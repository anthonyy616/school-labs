#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D {
private:
  double x;
  double y;

public:
  // Constructors
  Vector2D();
  Vector2D(double xVal, double yVal);

  // Display function
  void display() const;

  // Arithmetic operators
  Vector2D operator+(const Vector2D &other) const;
  Vector2D operator-(const Vector2D &other) const;

  // Comparison operators
  bool operator==(const Vector2D &other) const;
  bool operator!=(const Vector2D &other) const;

  // Subscript operator with bounds checking
  double &operator[](int index);
  const double &operator[](int index) const;

  // Stream operators (friend)
  friend std::ostream &operator<<(std::ostream &os, const Vector2D &v);
  friend std::istream &operator>>(std::istream &is, Vector2D &v);
};

#endif