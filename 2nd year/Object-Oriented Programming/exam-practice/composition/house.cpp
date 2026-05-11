#include <string>

using namespace std;

// House - Room composition example
class Room {
private:
  string name;
  double size;

public:
  Room(string n = "", double s = 0.0) : name(n), size(s) {}
};
