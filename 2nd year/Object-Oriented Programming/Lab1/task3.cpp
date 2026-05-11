#include <iostream>

using namespace std;

int main() {
    int intVal;
    double doubleVal;

    // 1. Prompts the user to enter:
    cout << "Enter an integer value: ";
    cin >> intVal;

    cout << "Enter a double value: ";
    cin >> doubleVal;

    // 2. Computes:
    double sum = intVal + doubleVal;

    
    int intFromDouble = static_cast<int>(doubleVal); // Explicitly convert double to int
    
    
    int divisionResult = intVal / static_cast<int>(doubleVal); 

    // 3. Display all results
    cout << "\nResults:" << endl;
    cout << "Sum: " << sum << endl;
    cout << "Integer Division (intVal / static_cast<int>(doubleVal)): " << divisionResult << endl;

    return 0;
}
