#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Task 1: Storing Numbers in a Vector
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        int num;
        cout << "Enter number " << i << ": ";
        cin >> num;
        vec.push_back(num);
    }

    cout << "Numbers stored in vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl << endl;

    return 0;
}