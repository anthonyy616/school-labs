// main.cpp
#include "Parallelogram.h"
#include <iostream>

int main() {
    std::cout << "=== Parallelogram Class Demo (Separated Files) ===\n\n";

    Parallelogram p1(6.0, 4.0, 30.0);
    p1.display();

    Parallelogram p2;
    std::cout << "\nEnter data for second parallelogram:\n";
    p2.input();
    p2.display();

    Parallelogram rhombus(5.0, 5.0, 60.0);
    std::cout << "\nRhombus Test:\n";
    rhombus.display();

    return 0;
}