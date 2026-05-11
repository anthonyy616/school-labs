#include "MyArray.h"
#include <iostream>
#include <cmath>

using namespace std;

// Point Implementation 
Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {}

void Point::display() const {
    cout << "(" << x << ", " << y << ")";
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

double Point::distanceTo(const Point& other) const {
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
}


Line::Line(Point p1, Point p2) : start(p1), end(p2) {} // line implementation

void Line::display() const {
    cout << "Line Segment: ";
    start.display();
    cout << " to ";
    end.display();
    cout << endl;
}

double Line::length() const {
    return start.distanceTo(end);
}

double Line::slope() const {
    if (abs(end.getX() - start.getX()) < 1e-9) {
        return 1.79769e+308; //  infinity
    }
    return (end.getY() - start.getY()) / (end.getX() - start.getX());
}

Point Line::midpoint() const {
    return Point((start.getX() + end.getX()) / 2.0, (start.getY() + end.getY()) / 2.0);
}
