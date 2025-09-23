#include "numberset.h"
#include <iostream>

int main() {
    NumberSet set;

    std::cout << "Enter 20 numbers between 10 and 100:\n";
    for (int i = 0; i < 20; i++) {
        int value;
        std::cout << "Enter number " << (i + 1) << ": ";
        std::cin >> value;
        set.addNumber(value);
    }

    set.displayUnique();
    return 0;
}
