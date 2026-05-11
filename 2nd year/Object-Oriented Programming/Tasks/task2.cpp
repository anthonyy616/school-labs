#include <iostream>

int main() {
    char inputChar;
    std::cout << "Enter a case number (e.g., 1, 2, 3): ";
    std::cin >> inputChar;

    // Turning the character to an integer using static_cast
    // To get the numeric value of the digit, we subtract '0'
    int caseNumber = static_cast<int>(inputChar - '0');

    std::cout << "Switching on case number: " << caseNumber << std::endl;

    
    switch (caseNumber) {
        case 1:
            std::cout << "Result: You selected Case 1." << std::endl;
            break; // Break ensures we exit the switch and don't go through all cases
        case 2:
            std::cout << "Result: You selected Case 2." << std::endl;
            break;
        case 3:
            std::cout << "Result: You selected Case 3." << std::endl;
            break;
        default:
            std::cout << "Result: Case not found." << std::endl;
            break;
    }

    return 0;
}
