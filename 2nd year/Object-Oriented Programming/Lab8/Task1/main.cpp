#include "MyArray.h"
#include <iostream>

using namespace std;

int main() {
    cout << " Point-Line Relationship " << endl;
    
    Point p1(0, 0);
    Point p2(3, 4);
    Line line(p1, p2);
    
    line.display();
    
    
    cout << "Length of the line: " << line.length() << endl;
    cout << "Slope of the line: " << line.slope() << endl;
    cout << "Midpoint: ";
    line.midpoint().display();
    cout << endl;

    return 0;
}
