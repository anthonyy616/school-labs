#ifndef MYARRAY_H
#define MYARRAY_H

#include <string>
#include <vector>

using namespace std;

// Task 2: House-Room Relationship
class Room {
private:
    string name;
    double size;

public:
    Room(string roomName = "Unknown", double roomSize = 0.0);
    void display() const;
    
    // Getters
    string getName() const;
    double getSize() const;
};

class House {
private:
    vector<Room> rooms;

public:
    House();
    void addRoom(const Room& room);
    void display() const;
    
    // Extensions
    double totalSize() const;
    int roomCount() const;
    void searchRoom(const string& name) const;
};

#endif
