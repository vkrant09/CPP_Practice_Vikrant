#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <iostream>
#include <string>

class HugeInteger {
private:
    static const int maxDigits = 40;
    int digits[maxDigits]; // store each digit

public:
    HugeInteger();  

    void input(const std::string& number);
    void output() const;

    HugeInteger add(const HugeInteger& other) const;
    HugeInteger subtract(const HugeInteger& other) const;

    bool isEqualTo(const HugeInteger& other) const;
    bool isNotEqualTo(const HugeInteger& other) const;
    bool isGreaterThan(const HugeInteger& other) const;
    bool isLessThan(const HugeInteger& other) const;
    bool isGreaterThanOrEqualTo(const HugeInteger& other) const;
    bool isLessThanOrEqualTo(const HugeInteger& other) const;

    bool isZero() const;
};

#endif
