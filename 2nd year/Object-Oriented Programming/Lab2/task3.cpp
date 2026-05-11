#include <iostream>

using namespace std;

int main() {
    char selection;
    double num1, num2;

    do {
        cout << "--- Symbol-Based Calculator ---" << endl;
        cout << "+ : Addition" << endl;
        cout << "- : Subtraction" << endl;
        cout << "* : Multiplication" << endl;
        cout << ". : Terminate program" << endl;
        cout << "Select an operator or '.' to quit: ";
        cin >> selection;

        // Use switch for symbol selection
        switch (selection) {
            case '+':
                cout << "Enter two numeric values: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
                break;
            case '-':
                cout << "Enter two numeric values: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
                break;
            case '*':
                cout << "Enter two numeric values: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
                break;
            case '.':
                cout << "Terminating program..." << endl;
                break;
            default:
                cout << "Invalid symbol. Please use +, -, *, or ." << endl;
                break;
        }
        cout << endl;

    } while (selection != '.');

    return 0;
}
