#include <iostream>


using namespace std;

void printValue(int x) {
    cout << "Integer: " << x << "\t" << "From func 1" << endl;
}
void printValue(int x, int y) {
    cout << "Integer: " << x << "\t" << y << "\t" << "From func 2" << endl;
}
void printValue(const string x) {
    cout << "String: " << x << endl;
}

int main() {
    printValue(42);
    printValue(3, 7);
    printValue("Hello, World!");

    return 0;
}