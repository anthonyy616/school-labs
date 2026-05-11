#include <iostream>

int main() {
    // 1. Using std::cout explicitly in each statement
    std::cout << "Hello, World! (Direct std::cout access)" << std::endl;

    // 2. Using using std::cout; to allow direct access to cout
    {
        using std::cout;
        using std::endl;
        cout << "Hello, World! (via using std::cout)" << endl;
    }

    // 3. Using using namespace std; to enable direct access to all standard library names
    {
        using namespace std;
        cout << "Hello, World! (via using namespace std)" << endl;
    }

    return 0;
}
