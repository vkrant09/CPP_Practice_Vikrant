#include "Complex.h"
#include <stdexcept>

// constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// addition
Complex Complex::operator+(const Complex& rhs) const {
    return Complex(real + rhs.real, imag + rhs.imag);
}

// subtraction
Complex Complex::operator-(const Complex& rhs) const {
    return Complex(real - rhs.real, imag - rhs.imag);
}

// multiplication
Complex Complex::operator*(const Complex& rhs) const {
    return Complex(real * rhs.real - imag * rhs.imag,
                   real * rhs.imag + imag * rhs.real);
}

// division
Complex Complex::operator/(const Complex& rhs) const {
    double denom = rhs.real * rhs.real + rhs.imag * rhs.imag;
    if (denom == 0.0) throw std::runtime_error("Division by zero complex number.");
    return Complex((real * rhs.real + imag * rhs.imag) / denom,
                   (imag * rhs.real - real * rhs.imag) / denom);
}

// compound assignments
Complex& Complex::operator+=(const Complex& rhs) {
    real += rhs.real;
    imag += rhs.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
    real -= rhs.real;
    imag -= rhs.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
    double tempReal = real * rhs.real - imag * rhs.imag;
    double tempImag = real * rhs.imag + imag * rhs.real;
    real = tempReal;
    imag = tempImag;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
    double denom = rhs.real * rhs.real + rhs.imag * rhs.imag;
    if (denom == 0.0) throw std::runtime_error("Division by zero complex number.");
    double tempReal = (real * rhs.real + imag * rhs.imag) / denom;
    double tempImag = (imag * rhs.real - real * rhs.imag) / denom;
    real = tempReal;
    imag = tempImag;
    return *this;
}

// equality
bool Complex::operator==(const Complex& rhs) const {
    return (real == rhs.real && imag == rhs.imag);
}

bool Complex::operator!=(const Complex& rhs) const {
    return !(*this == rhs);
}

// output
std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << "(" << c.real << (c.imag >= 0 ? " + " : " - ")
        << std::abs(c.imag) << "i)";
    return out;
}

// input
std::istream& operator>>(std::istream& in, Complex& c) {
    in >> c.real >> c.imag;
    return in;
}
