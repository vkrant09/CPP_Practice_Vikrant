#include "Polynomial.h"
#include <iomanip>

// constructor
Polynomial::Polynomial(int degree) {
    coefficients.resize(degree + 1, 0);
}

// input operator
std::istream& operator>>(std::istream& in, Polynomial& p) {
    int degree;
    std::cout << "Enter degree of polynomial: ";
    in >> degree;
    p.coefficients.assign(degree + 1, 0);

    std::cout << "Enter coefficients from highest degree to constant term:\n";
    for (int i = degree; i >= 0; i--) {
        std::cout << "Coefficient of x^" << i << ": ";
        in >> p.coefficients[i];
    }
    return in;
}

// output operator
std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    bool firstTerm = true;
    for (int i = p.coefficients.size() - 1; i >= 0; i--) {
        int coef = p.coefficients[i];
        if (coef != 0) {
            if (!firstTerm) {
                out << (coef > 0 ? " + " : " - ");
            } else if (coef < 0) {
                out << "-";
            }
            if (i == 0 || abs(coef) != 1) {
                out << abs(coef);
            }
            if (i > 0) out << "x";
            if (i > 1) out << "^" << i;
            firstTerm = false;
        }
    }
    if (firstTerm) out << 0; // all coeffs were 0
    return out;
}

// addition
Polynomial Polynomial::operator+(const Polynomial& rhs) const {
    int maxDegree = std::max(coefficients.size(), rhs.coefficients.size());
    Polynomial result(maxDegree - 1);
    for (int i = 0; i < maxDegree; i++) {
        int a = (i < coefficients.size() ? coefficients[i] : 0);
        int b = (i < rhs.coefficients.size() ? rhs.coefficients[i] : 0);
        result.coefficients[i] = a + b;
    }
    return result;
}

// subtraction
Polynomial Polynomial::operator-(const Polynomial& rhs) const {
    int maxDegree = std::max(coefficients.size(), rhs.coefficients.size());
    Polynomial result(maxDegree - 1);
    for (int i = 0; i < maxDegree; i++) {
        int a = (i < coefficients.size() ? coefficients[i] : 0);
        int b = (i < rhs.coefficients.size() ? rhs.coefficients[i] : 0);
        result.coefficients[i] = a - b;
    }
    return result;
}

// multiplication
Polynomial Polynomial::operator*(const Polynomial& rhs) const {
    int degreeA = coefficients.size() - 1;
    int degreeB = rhs.coefficients.size() - 1;
    Polynomial result(degreeA + degreeB);

    for (int i = 0; i <= degreeA; i++) {
        for (int j = 0; j <= degreeB; j++) {
            result.coefficients[i + j] += coefficients[i] * rhs.coefficients[j];
        }
    }
    return result;
}
