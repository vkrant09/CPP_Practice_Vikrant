#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // constructor
    Complex(double r = 0.0, double i = 0.0);

    // getters
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // operator overloads
    Complex operator+(const Complex& rhs) const;
    Complex operator-(const Complex& rhs) const;
    Complex operator*(const Complex& rhs) const;
    Complex operator/(const Complex& rhs) const;

    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;

    // friends for I/O
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    friend std::istream& operator>>(std::istream& in, Complex& c);
};

#endif
