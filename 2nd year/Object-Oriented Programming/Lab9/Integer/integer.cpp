#include "Integer.h"

Integer::Integer() : value(0) {}

Integer::Integer(int val) : value(val) {}

void Integer::display() const { std::cout << value; }

Integer Integer::operator+(const Integer &other) const {
  return Integer(value + other.value);
}

Integer Integer::operator-(const Integer &other) const {
  return Integer(value - other.value);
}

bool Integer::operator==(const Integer &other) const {
  return value == other.value;
}

bool Integer::operator!=(const Integer &other) const {
  return value != other.value;
}

Integer &Integer::operator++() {
  ++value;
  return *this;
}

Integer Integer::operator++(int) {
  Integer temp = *this;
  ++value;
  return temp;
}

std::ostream &operator<<(std::ostream &os, const Integer &obj) {
  os << obj.value;
  return os;
}

std::istream &operator>>(std::istream &is, Integer &obj) {
  is >> obj.value;
  return is;
}