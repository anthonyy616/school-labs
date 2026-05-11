#include <iostream>

using namespace std;

int main() {
    int a;
    int &ref_a = a; // refA is a reference to a
    ref_a = 20; // Modify the value of a through the reference
    cout << "Value of a: " << a << "," << "\t" << ref_a  << endl; // Output: Value of a: 20

    a = 30;
    cout << "Value of ref_a: " << a << "," << "\t" << ref_a << endl; // Output: Value of ref_a: 30
    return 0;
}