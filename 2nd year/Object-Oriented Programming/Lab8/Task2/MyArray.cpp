#include "MyArray.h"
#include <iostream>
#include <iomanip>

using namespace std; 


Room::Room(string roomName, double roomSize) : name(roomName), size(roomSize) {}

void Room::display() const {
    cout << "  - Room: " << left << setw(15) << name 
              << " | Size: " << size << " sq. units" << endl;
}

string Room::getName() const { return name; }
double Room::getSize() const { return size; }


House::House() {} //house implementation

void House::addRoom(const Room& room) {
    rooms.push_back(room);
}

void House::display() const {
    cout << "--- House Structure ---" << endl;
    if (rooms.empty()) {
        cout << "The house is empty." << endl;
        return;
    }
    for (const auto& room : rooms) {
        room.display();
    }
}

double House::totalSize() const {
    double total = 0;
    for (const auto& room : rooms) {
        total += room.getSize();
    }
    return total;
}

int House::roomCount() const {
    return static_cast<int>(rooms.size());
}

void House::searchRoom(const string& name) const {
    bool found = false;
    for (const auto& room : rooms) {
        if (room.getName() == name) {
            cout << "Found: ";
            room.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Room '" << name << "' not found." << endl;
    }
}
