#include <iostream>
#include <vector>

using namespace std;

int a = 10, b = 20;

void swap(int &x, int &y) {
    int temp = x; // Store the value of x in a temporary variable
    x = y;        // Assign the value of y to x
    y = temp;     // Assign the value of temp (original x) to y
}

int main() {
    cout << "Before swap: a = " << a << ", b = " << b << endl; // Output: Before swap: a = 10, b = 20
    swap(a, b); // Call the swap function with a and b as arguments
    cout << "After swap: a = " << a << ", b = " << b << endl; // Output: After swap: a = 20, b = 10

    return 0;
}