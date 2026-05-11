#ifndef MYARRAY_H
#define MYARRAY_H

// Point-Line Relationship
class Point {
private:
    double x, y;

public:
    Point(double x_val = 0, double y_val = 0);
    void display() const;
    
    double getX() const; //getter for extension
    double getY() const;
    
    double distanceTo(const Point& other) const;
};

class Line {
private:
    Point start;
    Point end;

public:
    Line(Point p1, Point p2);
    void display() const;
    
    double length() const;
    double slope() const;
    Point midpoint() const;
};

#endif
