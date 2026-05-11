#include <iostream>

using namespace std;

int main() {
    // --- Task 1 (a): Sum of Floating-Point Numbers ---
    cout << "--- Task 1 (a): Sum of Floating-Point Numbers ---" << endl;
    float sum = 0.0f;
    float currentFloat;
    cout << "Please enter five floating-point numbers:" << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << "Enter number " << i << ": ";
        cin >> currentFloat;
        sum += currentFloat;
    }
    cout << "The total sum is: " << sum << endl << endl;

    // --- Task 1 (b): Smallest Integer Finder ---
    cout << "--- Task 1 (b): Smallest Integer Finder ---" << endl;
    int smallest;
    int currentInt;
    cout << "Please enter five integers:" << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << "Enter integer " << i << ": ";
        cin >> currentInt;
        if (i == 1 || currentInt < smallest) {
            smallest = currentInt;
        }
    }
    cout << "The smallest value is: " << smallest << endl << endl;

    // --- Task 1 (c): Power Calculation ---
    cout << "--- Task 1 (c): Power Calculation ---" << endl;
    int n, m;
    cout << "Enter base integer (n): ";
    cin >> n;
    cout << "Enter exponent integer (m): ";
    cin >> m;

    long long result = 1;
    if (m < 0) {
        cout << "Negative number." << endl;
    } else {
        for (int i = 0; i < m; ++i) {
            result *= n;
        }
        cout << n << "^" << m << " = " << result << endl;
    }

    return 0;
}
