#include <iostream>

// Function using reference parameters
void swapByReference(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

// Function using pointer parameters
void swapByPointer(char *a, char *b) {
    if (a && b) {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {
    char char1 = 'A', char2 = 'B';

    std::cout << "Initial values: char1 = " << char1 << ", char2 = " << char2 << std::endl;

    // Demonstrate Swap by Reference
    std::cout << "\nSwapping using references..." << std::endl;
    swapByReference(char1, char2);
    std::cout << "After reference swap: char1 = " << char1 << ", char2 = " << char2 << std::endl;

    // Demonstrate Swap by Pointer (resetting first to show it works)
    char1 = 'A'; char2 = 'B';
    std::cout << "\nResetting values: char1 = " << char1 << ", char2 = " << char2 << std::endl;
    std::cout << "Swapping using pointers..." << std::endl;
    swapByPointer(&char1, &char2);
    std::cout << "After pointer swap: char1 = " << char1 << ", char2 = " << char2 << std::endl;

    return 0;
}


    /*
     * Brief comment on differences:
     * 1. Syntax: Reference parameters look like normal variables inside the function, while pointers 
     *    require dereferencing (*a).
     * 2. Safety: References cannot be null and must be initialized, making them generally safer. 
     *    Pointers can be null, so they should be checked before use.
     * 3. Call site: swapByReference(x, y) vs swapByPointer(&x, &y). References provide a cleaner
     *    syntax at the call site.
     */
