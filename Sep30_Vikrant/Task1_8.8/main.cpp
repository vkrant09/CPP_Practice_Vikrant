#include <iostream>
#include <iomanip>

int main() {
    const int SIZE = 5;

    // (a) Declare and initialize array with even numbers 2,4,6,8,10
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    // (b) Declare a pointer to unsigned int
    unsigned int* vPtr = nullptr;

    // (c) Print using array subscript
    std::cout << "(c) Using array subscript:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << "values[" << i << "] = " << values[i] << "\n";
    }

    // (d) Assign starting address of array to pointer
    vPtr = values;       // array name decays to address of first element
    vPtr = &values[0];   // alternative way

    // (e) Print using pointer/offset with vPtr
    std::cout << "\n(e) Using pointer/offset with vPtr:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << "*(vPtr + " << i << ") = " << *(vPtr + i) << "\n";
    }

    // (f) Print using pointer/offset with array name
    std::cout << "\n(f) Using pointer/offset with array name:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << "*(values + " << i << ") = " << *(values + i) << "\n";
    }

    // (g) Print using pointer subscript notation
    std::cout << "\n(g) Using pointer subscript (vPtr[i]):\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << "vPtr[" << i << "] = " << vPtr[i] << "\n";
    }

    // (h) Access the 5th element (index 4) in four ways
    std::cout << "\n(h) Fifth element in different notations:\n";
    std::cout << "values[4] = " << values[4] << "\n";
    std::cout << "*(values + 4) = " << *(values + 4) << "\n";
    std::cout << "vPtr[4] = " << vPtr[4] << "\n";
    std::cout << "*(vPtr + 4) = " << *(vPtr + 4) << "\n";

    // (i) vPtr + 3 (address and value)
    vPtr = values; // reset pointer to start
    std::cout << "\n(i) vPtr + 3 points to address " << (vPtr + 3)
              << " with value = " << *(vPtr + 3) << "\n";

    // (j) vPtr initially points to values[4], then subtract 4
    vPtr = &values[4];
    vPtr -= 4;
    std::cout << "\n(j) After vPtr -= 4, it points to address " << vPtr
              << " with value = " << *vPtr << "\n";

    return 0;
}
