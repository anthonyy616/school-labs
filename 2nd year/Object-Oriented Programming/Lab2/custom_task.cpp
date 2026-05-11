#include <iostream>

#include <cstdlib>

using namespace std;

int main() {

    int number;
    int choice;

    cout << "Enter the number to analyze: ";
    cin >> number;

    do {
        cout << "\nNumber Analyzer Menu:\n";
        cout << "1. Check if the number is even or odd\n";
        cout << "2. Check if the number is prime\n";
        cout << "3. Show the sum of digits\n";
        cout << "4. Enter a new number\n";
        cout << "5. Exit\n";
        cout << "Choose (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (number % 2 == 0) {
                    cout << number << " is even." << endl;
                } else {
                    cout << number << " is odd." << endl;
                }
                break;

            case 2: {
                if (number <= 1) {
                    cout << number << " is not prime." << endl;
                } else {
                    bool isPrime = true;
                    for (int i = 2; i * i <= number; ++i) {
                        if (number % i == 0) {
                            isPrime = false;
                            break;
                        }
                    }

                    if (isPrime) {
                        cout << number << " is prime." << endl;
                    } else {
                        cout << number << " is not prime." << endl;
                    }
                }
                break;
            }

            case 3: {
                int sum = 0;
                int temp = abs(number);

                if (temp == 0) {
                    sum = 0;
                } else {
                    while (temp != 0) {
                        sum += temp % 10;
                        temp /= 10;
                    }
                }

                cout << "The sum of digits of " << number << " is " << sum << "." << endl;
                break;
            }

            case 4:
                cout << "Enter a new number: ";
                cin >> number;
                break;

            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid selection. Please enter a valid option (1-5)." << endl;
                break;
        }

    } while (choice != 5);

    return 0;
}
