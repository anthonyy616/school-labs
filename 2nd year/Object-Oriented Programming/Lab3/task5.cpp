#include <iostream>

// Function for addition
double add(double a, double b) {
    return a + b;
}

// Function for subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function for multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function for division
double divide(double a, double b) {
    if (b == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return 0; // Or handle as NaN/Inf
    }
    return a / b;
}

void showMenu() {
    std::cout << "\n--- Modular Calculator ---" << std::endl;
    std::cout << "1. Addition (+)" << std::endl;
    std::cout << "2. Subtraction (-)" << std::endl;
    std::cout << "3. Multiplication (*)" << std::endl;
    std::cout << "4. Division (/)" << std::endl;
    std::cout << "5. Quit" << std::endl;
    std::cout << "Select an operation (1-5): ";
}

int main() {
    int choice;
    double num1, num2, result;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting calculator. Goodbye!" << std::endl;
            break;
        }

        if (choice < 1 || choice > 5) {
            std::cout << "Invalid choice. Please try again." << std::endl;
            continue;
        }

        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
                break;
            case 2:
                result = subtract(num1, num2);
                std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
                break;
            case 3:
                result = multiply(num1, num2);
                std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
                break;
            case 4:
                if (num2 != 0) {
                    result = divide(num1, num2);
                    std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
                } else {
                    std::cout << "Cannot divide by zero." << std::endl;
                }
                break;
        }
    }

  
    return 0;
}

  /*
     * Answer: Why is it better to implement each operation as a separate function rather than writing all logic inside main()?
     * 1. Modularity: Each function has a single responsibility, making the code easier to understand and manage.
     * 2. Reusability: These functions can be reused in other parts of the program or even in other projects.
     * 3. Maintainability: If a bug is found in an operation (e.g., division logic), it only needs to be fixed in one place.
     * 4. Readability: main() remains clean and focused on high-level control flow (the menu and user interaction).
     */
