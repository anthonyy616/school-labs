// Parallelogram.h  (or just put everything in main.cpp for Task 1)
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Parallelogram {
private:
    double sideA;      // length of one side
    double sideB;      // length of adjacent side
    double angle;      // angle in degrees between sideA and sideB

public:
    // Default Constructor
    Parallelogram() : sideA(0), sideB(0), angle(0) {}

    // Parameterized Constructor
    Parallelogram(double a, double b, double theta) {
        sideA = (a > 0) ? a : 0;
        sideB = (b > 0) ? b : 0;
        angle = (theta > 0 && theta < 180) ? theta : 0;
    }

    // Input function
    void input() {
        std::cout << "Enter length of side A: ";
        std::cin >> sideA;
        std::cout << "Enter length of side B: ";
        std::cin >> sideB;
        std::cout << "Enter angle between sides A and B (in degrees): ";
        std::cin >> angle;

        if (sideA <= 0) sideA = 0;
        if (sideB <= 0) sideB = 0;
        if (angle <= 0 || angle >= 180) angle = 0;
    }

    // Calculate Area
    double calculateArea() const {
        if (sideA == 0 || sideB == 0 || angle == 0) return 0.0;
        double rad = angle * 3.14159265358979323846 / 180.0;
        return sideA * sideB * sin(rad);
    }

    // Calculate Perimeter
    double calculatePerimeter() const {
        return 2 * (sideA + sideB);
    }

    // Calculate Height (corresponding to base sideA)
    double calculateHeight() const {
        if (sideA == 0 || sideB == 0 || angle == 0) return 0.0;
        double rad = angle * 3.14159265358979323846 / 180.0;
        return sideB * sin(rad);
    }

    // Check if it is a Rhombus
    bool isRhombus() const {
        return (sideA > 0 && sideB > 0 && abs(sideA - sideB) < 1e-6);
    }

    // Display parallelogram information
    void display() const {
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "\n=== Parallelogram Info ===\n";
        std::cout << "Side A     : " << sideA << std::endl;
        std::cout << "Side B     : " << sideB << std::endl;
        std::cout << "Angle      : " << angle << " degrees" << std::endl;
        std::cout << "Area       : " << calculateArea() << std::endl;
        std::cout << "Perimeter  : " << calculatePerimeter() << std::endl;
        std::cout << "Height     : " << calculateHeight() << std::endl;
        std::cout << "Is Rhombus?: " << (isRhombus() ? "Yes" : "No") << std::endl;
        std::cout << "========================\n";
    }
};

int main() {
    std::cout << "=== Parallelogram Class Demo ===\n\n";

    // Test 1: Using parameterized constructor
    Parallelogram p1(5.0, 3.0, 60.0);
    std::cout << "Test 1 - Parameterized Constructor:\n";
    p1.display();

    // Test 2: Using input
    Parallelogram p2;
    std::cout << "\nTest 2 - User Input:\n";
    p2.input();
    p2.display();

    // Test 3: Rhombus check
    Parallelogram rhombus(4.0, 4.0, 45.0);
    std::cout << "\nTest 3 - Rhombus Test:\n";
    rhombus.display();

    return 0;
}