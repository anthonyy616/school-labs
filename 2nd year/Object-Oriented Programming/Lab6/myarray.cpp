// MyArray.cpp
#include "MyArray.h"
#include <iostream>
#include <iomanip>

using namespace std;

MyArray::MyArray(int s) {
    size = (s > 0) ? s : 0;
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;               // safe zero-initialization
        }
    } else {
        data = nullptr;
    }
}

MyArray::~MyArray() {
    delete[] data;   // prevents memory leak
}

void MyArray::display() const {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int MyArray::getSize() const {
    return size;
}

int MyArray::getElement(int index) const {
    if (index < 0 || index >= size) {
        cout << "Error: Invalid index!" << endl;
        return 0;
    }
    return data[index];
}

void MyArray::setElement(int index, int value) {
    if (index < 0 || index >= size) {
        cout << "Error: Invalid index!" << endl;
        return;
    }
    data[index] = value;
}

int MyArray::find(int value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) return i;
    }
    return -1;   // not found
}

int MyArray::sum() const {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += data[i];
    }
    return total;
}

double MyArray::average() const {
    if (size == 0) return 0.0;
    return static_cast<double>(sum()) / size;
}

void MyArray::reverse() {
    for (int i = 0; i < size / 2; i++) {
        int temp = data[i];
        data[i] = data[size - 1 - i];
        data[size - 1 - i] = temp;
    }
}

// ==================== ORIGINAL METHODS ====================

void MyArray::inputElements() {
    if (size == 0) {
        cout << "Cannot input into empty array.\n";
        return;
    }
    cout << "Enter " << size << " integer elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element [" << i << "]: ";
        cin >> data[i];
    }
}

int MyArray::getMax() const {
    if (size == 0) return 0;
    int maxVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > maxVal) maxVal = data[i];
    }
    return maxVal;
}

int MyArray::getMin() const {
    if (size == 0) return 0;
    int minVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < minVal) minVal = data[i];
    }
    return minVal;
}