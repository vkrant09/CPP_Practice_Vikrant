#ifndef DOUBLE_SUBSCRIPTED_ARRAY_H
#define DOUBLE_SUBSCRIPTED_ARRAY_H

#include <iostream>

class DoubleSubscriptedArray {
private:
    int rows;
    int cols;
    int* data;

public:
    // constructor
    DoubleSubscriptedArray(int r = 1, int c = 1);

    // copy constructor
    DoubleSubscriptedArray(const DoubleSubscriptedArray& other);

    // destructor
    ~DoubleSubscriptedArray();

    // assignment operator
    DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray& rhs);

    // equality operators
    bool operator==(const DoubleSubscriptedArray& rhs) const;
    bool operator!=(const DoubleSubscriptedArray& rhs) const;

    // () operator (non-const and const versions)
    int& operator()(int r, int c);
    const int& operator()(int r, int c) const;

    // getters
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // friend stream operators
    friend std::ostream& operator<<(std::ostream& out, const DoubleSubscriptedArray& arr);
    friend std::istream& operator>>(std::istream& in, DoubleSubscriptedArray& arr);
};

#endif
