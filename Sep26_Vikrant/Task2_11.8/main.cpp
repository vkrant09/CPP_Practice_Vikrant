#include "complex.h"
#include <iostream>

int main() {
    Complex c1, c2;

    std::cout << "Enter first complex number (real imag): ";
    std::cin >> c1;

    std::cout << "Enter second complex number (real imag): ";
    std::cin >> c2;

    std::cout << "\nYou entered:\n";
    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n";

    std::cout << "\nOperations:\n";
    std::cout << "c1 + c2 = " << (c1 + c2) << "\n";
    std::cout << "c1 - c2 = " << (c1 - c2) << "\n";
    std::cout << "c1 * c2 = " << (c1 * c2) << "\n";

    try {
        std::cout << "c1 / c2 = " << (c1 / c2) << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    std::cout << "\nComparisons:\n";
    std::cout << "c1 == c2 ? " << (c1 == c2 ? "true" : "false") << "\n";
    std::cout << "c1 != c2 ? " << (c1 != c2 ? "true" : "false") << "\n";

    return 0;
}
