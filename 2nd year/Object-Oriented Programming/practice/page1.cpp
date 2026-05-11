#include <iostream>
#include <iomanip>

using namespace std;

class Test{
    public:
        void display() {
            char c;
            string s = "";

            while (true) {
                cout << "Enter a character: " << endl;
                cin >> c;
        
                s +=c; //append the character to the string

                if (c == '.') {
                    break; //leave the loop if the user enters a period
                }
            }

            cout << "You entered:" << s << endl;
        }
};


int main() {

    Test obj;
    obj.display();
    return 0;
}