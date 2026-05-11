#include <iostream>

using namespace std;


class Line {


    private:
        int midpoint;
    public:
        int length;
        int height;
        //Function declarations
        //getInput()
        //displayinput()
        //task()

        void getInput() {
            cout << "Please enter length: ";
            cin >> length;
            cout << "Please enter height: ";
            cin >> height;
        }

        void displayInput() {
            cout << "Length: " << length << endl;
            cout << "Height: " << height << endl;
        }

        void drawGrid() {
            if length <= 0 || height <= 0 {
                cout << "Length and height must be positive integers." << endl;
                return;
            }
            if (length % 2 == 0) {
                midpoint = length / 2 - 1; // For even length, choose the left middle point
                return;
            }
            else if (length % 2 != 0) {
                midpoint = length / 2;
            }

            for (int row = 0; row < height; row++) {
                for (int col = 0; col <= length; col++) {
                    if (col == midpoint) {
                        cout << '#';
                    } else {
                        cout << '.';
                    }
                }
                cout << endl;
            }
        }

};

int main() {
    Line line1;
    line1.getInput();
    line1.drawGrid();

    return 0;
}