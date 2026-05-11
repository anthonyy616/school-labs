// main.cpp
#include "MyArray.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "=== MyArray Dynamic Array Demo ===\n\n";

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    MyArray arr(n);                     // constructor called here

    if (n > 0) {
        arr.inputElements();            // original method
    }

    cout << "\n--- Initial Array ---\n";
    arr.display();

    cout << "Size                  : " << arr.getSize() << endl;
    cout << "Sum                   : " << arr.sum() << endl;
    cout << "Average               : " << fixed << setprecision(2)
              << arr.average() << endl;
    cout << "Maximum value         : " << arr.getMax() << endl;
    cout << "Minimum value         : " << arr.getMin() << endl;

    // Demonstrate find
    int searchVal;
    cout << "\nEnter a value to search: ";
    cin >> searchVal;
    int idx = arr.find(searchVal);
    if (idx != -1)
        cout << "Found at index " << idx << endl;
    else
        cout << "Value not found.\n";

    // Demonstrate reverse
    arr.reverse();
    cout << "\nAfter reverse():\n";
    arr.display();

    // Demonstrate setElement + getElement
    if (n > 0) {
        int idxSet, newVal;
        cout << "\nEnter index and new value to update (e.g. 0 99): ";
        cin >> idxSet >> newVal;
        arr.setElement(idxSet, newVal);
        cout << "After setElement:\n";
        arr.display();

        cout << "Element at index 0 : " << arr.getElement(0) << endl;
    }

    cout << "\nProgram finished. Destructor will free memory automatically.\n";
    return 0;
}