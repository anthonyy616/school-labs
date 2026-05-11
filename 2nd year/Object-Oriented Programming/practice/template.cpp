#include <iostream>

using namespace std;

template <typename T> T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main () {
    auto a = 5, b = 10;
    cout << "Max b/w" << a << " and " << b << " is " << myMax<int>(5, 10) << endl;
    cout << "Max b/w" << a << " and " << b << " is " << myMax<double>(5.5, 1.5) << endl;
    cout << "Max b/w" << "g" << " and " << "e" << " is " << myMax<char>('g', 'e') << endl;
    return 0;
}