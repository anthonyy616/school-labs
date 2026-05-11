#include <iostream>
#include <string>

using namespace std;

class Date {
private:
  int day;
  int month;
  int year;

public:
  Date(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {
    cout << "Created Date" << endl;
  }

  // To copy date
  Date(const Date &other)
      : day(other.day), month(other.month), year(other.year) {
    cout << "Copied Date" << endl;
  }
};

int main() {
  Date today(11, 5, 2026);
  Date copy(today);

  return 0;
}