// Parallelogram.h
#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <iostream>

class Parallelogram {
private:
    double sideA;
    double sideB;
    double angle;   // in degrees

public:
    // Constructors
    Parallelogram();
    Parallelogram(double a, double b, double theta);

    // Member functions
    void input();
    double calculateArea() const;
    double calculatePerimeter() const;
    double calculateHeight() const;
    bool isRhombus() const;
    void display() const;
};

#endif