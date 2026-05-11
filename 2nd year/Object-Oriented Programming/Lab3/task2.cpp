#include <iostream>

// Function prototype before main
// Default arguments are specified here in the declaration
double computeVolume(double width = 1, double height = 1, double depth = 1);

int main() {
    std::cout << "Computing volume with different argument counts:" << std::endl;

    // All defaults: 1 * 1 * 1 = 1
    std::cout << "Volume (all defaults): " << computeVolume() << std::endl;

    // One argument specified: 5 * 1 * 1 = 5
    std::cout << "Volume (width=5): " << computeVolume(5) << std::endl;

    // Two arguments specified: 5 * 2 * 1 = 10
    std::cout << "Volume (width=5, height=2): " << computeVolume(5, 2) << std::endl;

    // All arguments specified: 5 * 2 * 3 = 30
    std::cout << "Volume (5, 2, 3): " << computeVolume(5, 2, 3) << std::endl;

    /*
     * Answer: Where should default arguments normally be specified?
     * Default arguments should normally be specified in the function declaration (usually in a header file 
     * or before main), not in the function definition. This allows the compiler to know the default 
     * values when the function is called in other parts of the program.
     */

    return 0;
}

// Function definition after main
double computeVolume(double width, double height, double depth) {
    return width * height * depth;
}
