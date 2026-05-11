#include <iostream>
#include <iomanip> // For setw, setprecision, fixed

using namespace std;

int main() {
    // 1. Declares
    int intVar = 42;
    double floatVar = 123.456789;

    // 2. Displays their values in a table format
    cout << "COMP218 Object-Oriented Programming" << endl;
    cout << "2025-26 Spring" << endl << endl;

    // Header
    cout << left << setw(15) << "Type" 
         << right << setw(20) << "Value (formatted)" << endl;
    cout << setfill('-') << setw(35) << "-" << setfill(' ') << endl;

    // Integer value
    cout << left << setw(15) << "Integer" 
         << right << setw(20) << intVar << endl;

    // Floating-point value with 2 decimal places
    cout << left << setw(15) << "Float (2dp)" 
         << right << setw(20) << fixed << setprecision(2) << floatVar << endl;

    // Floating-point value with 5 decimal places
    cout << left << setw(15) << "Float (5dp)" 
         << right << setw(20) << fixed << setprecision(5) << floatVar << endl;

    return 0;
}
