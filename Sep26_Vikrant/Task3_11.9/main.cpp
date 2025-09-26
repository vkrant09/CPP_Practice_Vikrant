#include "HugeInteger.h"
#include <iostream>

int main() {
    HugeInteger n1, n2, sum, diff;

    n1.input("12345678901234567890");
    n2.input("99999");

    std::cout << "n1 = "; n1.output(); std::cout << "\n";
    std::cout << "n2 = "; n2.output(); std::cout << "\n";

    sum = n1.add(n2);
    diff = n1.subtract(n2);

    std::cout << "n1 + n2 = "; sum.output(); std::cout << "\n";
    std::cout << "n1 - n2 = "; diff.output(); std::cout << "\n";

    std::cout << "n1 > n2 ? " << (n1.isGreaterThan(n2) ? "true" : "false") << "\n";
    std::cout << "n1 == n2 ? " << (n1.isEqualTo(n2) ? "true" : "false") << "\n";

    HugeInteger zero;
    std::cout << "zero = "; zero.output();
    std::cout << "  isZero? " << (zero.isZero() ? "true" : "false") << "\n";

    return 0;
}
