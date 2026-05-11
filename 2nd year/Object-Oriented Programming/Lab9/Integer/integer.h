#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>

class Integer {
private:
  int value;

public:
  // Constructors
  Integer();
  Integer(int val);

  // Display function
  void display() const;

  // Arithmetic operators (member functions)
  Integer operator+(const Integer &other) const;
  Integer operator-(const Integer &other) const;

  // Comparison operators
  bool operator==(const Integer &other) const;
  bool operator!=(const Integer &other) const;

  // Increment operators
  Integer &operator++();   // Pre-increment
  Integer operator++(int); // Post-increment

  // Stream operators (friend functions)
  friend std::ostream &operator<<(std::ostream &os, const Integer &obj);
  friend std::istream &operator>>(std::istream &is, Integer &obj);
};

#endif