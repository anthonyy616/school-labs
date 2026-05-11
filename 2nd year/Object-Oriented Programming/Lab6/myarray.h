// MyArray.h
#ifndef MYARRAY_H
#define MYARRAY_H

class MyArray {
private:
    int* data;   // pointer to dynamic array
    int size;    // number of elements

public:
    // Constructor
    MyArray(int s = 0);

    // Destructor
    ~MyArray();

    // Required member functions
    void display() const;
    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int value);
    int find(int value) const;
    int sum() const;
    double average() const;
    void reverse();

    // Original methods
    void inputElements();      // Original #1: user-friendly input
    int getMax() const;        // Original #2
    int getMin() const;        // Original #3
};

#endif