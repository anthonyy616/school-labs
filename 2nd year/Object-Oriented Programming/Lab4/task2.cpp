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

    // Task 2
    if (!vec.empty()) {
        int min_val = vec[0];
        int max_val = vec[0];
        for (int num : vec) {
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }
        cout << "Minimum value: " << min_val << endl;
        cout << "Maximum value: " << max_val << endl;
    }

    return 0;
}