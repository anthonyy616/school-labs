#include "MyArray.h"
#include <iostream>

int main() {
    std::cout << "House-Room Relationship" << std::endl;
    
    House myHouse;
    myHouse.addRoom(Room("Kitchen", 150.5));
    myHouse.addRoom(Room("Living Room", 300.0));
    myHouse.addRoom(Room("Bedroom", 200.0));
    
    myHouse.display();
    
    // Extensions
    std::cout << "Total House Size: " << myHouse.totalSize() << " sq. units" << std::endl;
    std::cout << "Number of Rooms: " << myHouse.roomCount() << std::endl;
    
    std::cout << "Searching for 'Kitchen'..." << std::endl;
    myHouse.searchRoom("Kitchen");

    return 0;
}
