#include "DoubleSubscriptedArray.h"
#include <iostream>

int main() {
    DoubleSubscriptedArray arr1(3, 4); // 3x4 matrix

    std::cout << "Enter 12 integers for a 3x4 array:\n";
    std::cin >> arr1;

    std::cout << "Array contents:\n" << arr1;

    arr1(1, 2) = 99; // use () as lvalue
    std::cout << "\nAfter setting arr1(1,2) = 99:\n" << arr1;

    DoubleSubscriptedArray arr2 = arr1; // copy constructor
    std::cout << "\nCopied array arr2:\n" << arr2;

    if (arr1 == arr2) {
        std::cout << "arr1 and arr2 are equal.\n";
    }

    return 0;
}
