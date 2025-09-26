#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>

class Polynomial {
private:
    std::vector<int> coefficients; // index = exponent, value = coefficient

public:
    Polynomial(int degree = 0);

    // I/O
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);
    friend std::istream& operator>>(std::istream& in, Polynomial& p);

    // operators
    Polynomial operator+(const Polynomial& rhs) const;
    Polynomial operator-(const Polynomial& rhs) const;
    Polynomial operator*(const Polynomial& rhs) const;
};

#endif
