#include <iostream>
#include <cmath>


// Formula: sqrt((x2-x1)^2 + (y2-y1)^2)

// Version for integer coordinates
double calculateDistance(int x1, int y1, int x2, int y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

// Version for double coordinates
double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int main() {
    // Demonstrate integer version
    int ix1 = 0, iy1 = 0, ix2 = 3, iy2 = 4;
    std::cout << "Integer Coordinates: (" << ix1 << "," << iy1 << ") to (" << ix2 << "," << iy2 << ")" << std::endl;
    std::cout << "Distance: " << calculateDistance(ix1, iy1, ix2, iy2) << std::endl;

    std::cout << "------------------------------------" << std::endl;

    // Demonstrate double version
    double dx1 = 1.5, dy1 = 2.0, dx2 = 4.5, dy2 = 6.0;
    std::cout << "Double Coordinates: (" << dx1 << "," << dy1 << ") to (" << dx2 << "," << dy2 << ")" << std::endl;
    std::cout << "Distance: " << calculateDistance(dx1, dy1, dx2, dy2) << std::endl;

    return 0;
}
