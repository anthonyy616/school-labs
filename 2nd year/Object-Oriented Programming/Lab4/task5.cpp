#include <iostream>
#include <vector>

using namespace std;



int main() {
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
    
    // Task 5: Reversing the Vector (print in reverse order)
    cout << "Vector in reverse order: ";
    for (int i = static_cast<int>(vec.size()) - 1; i >= 0; i--) {
        cout << vec[i] << " ";
    }
    cout << endl;

    
    return 0;
}