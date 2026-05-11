#include "date.cpp"
#include <iostream>
#include <string>

using namespace std;

class Person {
private:
  string name;
  int age;
  Date birthdate;

public:
  Person(string n, int a, Date b) : name(n), age(a), birthdate(b) {
    cout << "Created person: " << name << endl;
  }

  // To copy
  Person(const Person &other)
      : name(other.name), age(other.age), birthdate(other.birthdate) {
    cout << "Copied " << name << endl;
  }
};

Person anthony("anthony", 22, Date(10, 10, 2005));
Person copy(anthony);
