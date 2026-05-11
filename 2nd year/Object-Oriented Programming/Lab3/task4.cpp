#include <iostream>

const double PI = 3.142;

// Inline function to compute area of a circle
inline double computeArea(double radius) {
    return PI * radius * radius;
}

// Function to compute volume of a cylinder, reusing the area function
double computeCylinderVolume(double radius, double height) {
    return computeArea(radius) * height;
}

int main() {
    double r1 = 5.0, h1 = 10.0;
    double r2 = 2.5, h2 = 4.0;

    std::cout << "Circle Radius: " << r1 << " -> Area: " << computeArea(r1) << std::endl;
    std::cout << "Cylinder (r=" << r1 << ", h=" << h1 << ") -> Volume: " << computeCylinderVolume(r1, h1) << std::endl;

    std::cout << "\nCircle Radius: " << r2 << " -> Area: " << computeArea(r2) << std::endl;
    std::cout << "Cylinder (r=" << r2 << ", h=" << h2 << ") -> Volume: " << computeCylinderVolume(r2, h2) << std::endl;

    
    return 0;
}



/*
     * Answer: What is the purpose of using inline functions?
     * The purpose of inline functions is to reduce the overhead of a function call. 
     * When a function is marked 'inline', the compiler attempts to replace the function 
     * call with the actual code of the function at the call site. This is beneficial 
     * for small, frequently called functions where the cost of the call (stack 
     * operations, instruction jumps) is high relative to the function's task.
     */
