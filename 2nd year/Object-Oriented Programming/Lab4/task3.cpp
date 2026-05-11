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

    
     // Task 3: Computing Sum and Average
    int sum = 0;
    for (int num : vec) {
        sum += num;
    }
    double average = static_cast<double>(sum) / vec.size();
    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl << endl;


    return 0;
}


