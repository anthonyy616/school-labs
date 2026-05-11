// Parallelogram.cpp
#include "Parallelogram.h"
#include <cmath>
#include <iomanip>

using namespace std; 

Parallelogram::Parallelogram() : sideA(0), sideB(0), angle(0) {}

Parallelogram::Parallelogram(double a, double b, double theta) {
    sideA = (a > 0) ? a : 0;
    sideB = (b > 0) ? b : 0;
    angle = (theta > 0 && theta < 180) ? theta : 0;
}

void Parallelogram::input() {
    cout << "Enter length of side A: ";
    cin >> sideA;
    cout << "Enter length of side B: ";
    cin >> sideB;
    cout << "Enter angle between sides A and B (degrees): ";
    cin >> angle;

    if (sideA <= 0) sideA = 0;
    if (sideB <= 0) sideB = 0;
    if (angle <= 0 || angle >= 180) angle = 0;
}

double Parallelogram::calculateArea() const {
    if (sideA == 0 || sideB == 0 || angle == 0) return 0.0;
    double rad = angle * 3.14159265358979323846 / 180.0;
    return sideA * sideB * sin(rad);
}

double Parallelogram::calculatePerimeter() const {
    return 2 * (sideA + sideB);
}

double Parallelogram::calculateHeight() const {
    if (sideA == 0 || sideB == 0 || angle == 0) return 0.0;
    double rad = angle * 3.14159265358979323846 / 180.0;
    return sideB * sin(rad);
}

bool Parallelogram::isRhombus() const {
    return (sideA > 0 && sideB > 0 && fabs(sideA - sideB) < 1e-6);
}

void Parallelogram::display() const {
    cout << fixed << setprecision(4);
    cout << "\n=== Parallelogram Info ===\n";
    cout << "Side A     : " << sideA << endl;
    cout << "Side B     : " << sideB << endl;
    cout << "Angle      : " << angle << " degrees" << endl;
    cout << "Area       : " << calculateArea() << endl;
    cout << "Perimeter  : " << calculatePerimeter() << endl;
    cout << "Height     : " << calculateHeight() << endl;
    cout << "Is Rhombus?: " << (isRhombus() ? "Yes" : "No") << endl;
    cout << "========================\n";
}