#include "numberset.h"
#include <iostream>

NumberSet::NumberSet() {}

void NumberSet::addNumber(int value) {
    // validate range 10–100
    if (value < 10 || value > 100) {
        std::cout << "Invalid number, must be between 10 and 100.\n";
        return;
    }

    // check for duplicates
    for (int n : numbers) {
        if (n == value) {
            std::cout << "Duplicate ignored: " << value << "\n";
            return;
        }
    }

    // add if unique
    numbers.push_back(value);
}

void NumberSet::displayUnique() const {
    std::cout << "\nUnique numbers entered:\n";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}
