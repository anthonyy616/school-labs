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
       
    // Task 4: Searching for a Value
    int search_val;
    cout << "Enter number to search: ";
    cin >> search_val;

    bool found = false;
    int index = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == search_val) {
            found = true;
            index = i;
            break;
        }
    }

    if (found) {
        cout << "Value found at index " << index << endl << endl;
    } else {
        cout << "Value not found in vector." << endl << endl;
    }

    
    return 0;
}