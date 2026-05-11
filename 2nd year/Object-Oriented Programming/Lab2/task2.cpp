#include <iostream>

using namespace std;

int main() {
    int choice;
    double num1, num2;

    do {
        cout << "--- Menu-Driven Calculator ---" << endl;
        cout << "1 - Add" << endl;
        cout << "2 - Subtract" << endl;
        cout << "3 - Multiply" << endl;
        cout << "4 - Quit" << endl;
        cout << "Select an option (1-4): ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            cout << "Enter two numeric values: ";
            cin >> num1 >> num2;

            switch (choice) {
                case 1:
                    cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
                    break;
                case 2:
                    cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
                    break;
                case 3:
                    cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
                    break;
            }
            cout << endl;
        } else if (choice == 4) {
            cout << "Terminating program..." << endl;
        } else {
            cout << "Invalid. try again." << endl << endl;
        }

    } 
    while (choice != 4);

    return 0;
}
