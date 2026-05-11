#include <iostream>

using namespace std;

int main () {


   // --- Task 1 (c): Power Calculation ---
    cout << "--- Task 1 (c): Power Calculation ---" << endl;
    double n, m, control;
    control = 1;
    cout << "Enter base integer (n): ";
    cin >> n;
    cout << "Enter exponent integer (m): ";
    cin >> m;

    double result = 1;
    if (m < 0) {
        control = 0;
        m = m * -1;

    }
        for (int i = 0; i < m; ++i) {
            result *= n;
        }

        if (control == 0) {
            result = 1 / result;
        }

      cout << n << "^" << m << " = " << result << endl;

    return 0;
}


// if m<0, then convert m to a positive integer maybe using absolute and then do 1/n ^m where n is the positive integer