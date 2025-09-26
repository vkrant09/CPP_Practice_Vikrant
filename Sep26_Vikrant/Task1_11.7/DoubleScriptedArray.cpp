#include "DoubleSubscriptedArray.h"
#include <stdexcept>

// constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c)
    : rows(r), cols(c) {
    if (r <= 0 || c <= 0) {
        throw std::invalid_argument("Rows and columns must be positive.");
    }
    data = new int[rows * cols](); // initialize with 0
}

// copy constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& other)
    : rows(other.rows), cols(other.cols) {
    data = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
    }
}

// destructor
DoubleSubscriptedArray::~DoubleSubscriptedArray() {
    delete[] data;
}

// assignment operator
DoubleSubscriptedArray& DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& rhs) {
    if (this != &rhs) {
        delete[] data;
        rows = rhs.rows;
        cols = rhs.cols;
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = rhs.data[i];
        }
    }
    return *this;
}

// equality operators
bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& rhs) const {
    if (rows != rhs.rows || cols != rhs.cols) return false;
    for (int i = 0; i < rows * cols; i++) {
        if (data[i] != rhs.data[i]) return false;
    }
    return true;
}

bool DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray& rhs) const {
    return !(*this == rhs);
}

// () operator (non-const)
int& DoubleSubscriptedArray::operator()(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Invalid subscript");
    }
    return data[r * cols + c];
}

// () operator (const)
const int& DoubleSubscriptedArray::operator()(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Invalid subscript");
    }
    return data[r * cols + c];
}

// output operator
std::ostream& operator<<(std::ostream& out, const DoubleSubscriptedArray& arr) {
    for (int r = 0; r < arr.rows; r++) {
        for (int c = 0; c < arr.cols; c++) {
            out << arr(r, c) << " ";
        }
        out << "\n";
    }
    return out;
}

// input operator
std::istream& operator>>(std::istream& in, DoubleSubscriptedArray& arr) {
    for (int i = 0; i < arr.rows * arr.cols; i++) {
        in >> arr.data[i];
    }
    return in;
}
