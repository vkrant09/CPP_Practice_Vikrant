#include "Complex.h"
#include <iostream>

int main() {
    Complex c1(3, 4), c2(1, -2);

    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n\n";

    // arithmetic
    std::cout << "c1 + c2 = " << (c1 + c2) << "\n";
    std::cout << "c1 - c2 = " << (c1 - c2) << "\n";
    std::cout << "c1 * c2 = " << (c1 * c2) << "\n";
    std::cout << "c1 / c2 = " << (c1 / c2) << "\n\n";

    // compound
    Complex c3 = c1;
    c3 += c2;
    std::cout << "c1 += c2 => " << c3 << "\n";

    c3 = c1;
    c3 -= c2;
    std::cout << "c1 -= c2 => " << c3 << "\n";

    c3 = c1;
    c3 *= c2;
    std::cout << "c1 *= c2 => " << c3 << "\n";

    c3 = c1;
    c3 /= c2;
    std::cout << "c1 /= c2 => " << c3 << "\n\n";

    // comparisons
    std::cout << "c1 == c2 ? " << (c1 == c2 ? "true" : "false") << "\n";
    std::cout << "c1 != c2 ? " << (c1 != c2 ? "true" : "false") << "\n";

    return 0;
}
