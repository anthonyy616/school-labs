#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double result = 10.0 / 3;

    // 1. Default formatting
    cout << "1. Default formatting: " << result << endl;

    // 2. Using fixed
    cout << "2. Using fixed: " << fixed << result << endl;

    // 3. Using setprecision(2)

    cout << "3. Using setprecision(2) with fixed: " << setprecision(2) << result << endl;

    // 4. Using setprecision(8)
    cout << "4. Using setprecision(8) with fixed: " << setprecision(8) << result << endl;


    return 0;
}
