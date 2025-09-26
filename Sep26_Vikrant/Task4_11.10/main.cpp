#include "Polynomial.h"
#include <iostream>

int main() {
    Polynomial p1, p2;

    std::cout << "Enter first polynomial:\n";
    std::cin >> p1;

    std::cout << "\nEnter second polynomial:\n";
    std::cin >> p2;

    std::cout << "\nPolynomials entered:\n";
    std::cout << "P1(x) = " << p1 << "\n";
    std::cout << "P2(x) = " << p2 << "\n";

    std::cout << "\nOperations:\n";
    std::cout << "P1 + P2 = " << (p1 + p2) << "\n";
    std::cout << "P1 - P2 = " << (p1 - p2) << "\n";
    std::cout << "P1 * P2 = " << (p1 * p2) << "\n";

    return 0;
}
