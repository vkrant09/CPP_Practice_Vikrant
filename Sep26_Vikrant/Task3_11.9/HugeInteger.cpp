#include "HugeInteger.h"
#include <algorithm>
#include <stdexcept>

// constructor: initialize all digits to 0
HugeInteger::HugeInteger() {
    for (int i = 0; i < maxDigits; i++) {
        digits[i] = 0;
    }
}

// input from string
void HugeInteger::input(const std::string& number) {
    if (number.size() > maxDigits) {
        throw std::invalid_argument("Number too large (max 40 digits).");
    }
    // reset
    for (int i = 0; i < maxDigits; i++) digits[i] = 0;

    int start = maxDigits - number.size();
    for (size_t i = 0; i < number.size(); i++) {
        if (!isdigit(number[i])) throw std::invalid_argument("Invalid character.");
        digits[start + i] = number[i] - '0';
    }
}

// output number
void HugeInteger::output() const {
    int i = 0;
    while (i < maxDigits && digits[i] == 0) i++; // skip leading zeros
    if (i == maxDigits) std::cout << 0;
    else {
        for (; i < maxDigits; i++) std::cout << digits[i];
    }
}

// add
HugeInteger HugeInteger::add(const HugeInteger& other) const {
    HugeInteger result;
    int carry = 0;

    for (int i = maxDigits - 1; i >= 0; i--) {
        int sum = digits[i] + other.digits[i] + carry;
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }
    return result;
}

// subtract (assume *this >= other)
HugeInteger HugeInteger::subtract(const HugeInteger& other) const {
    HugeInteger result;
    int borrow = 0;

    for (int i = maxDigits - 1; i >= 0; i--) {
        int diff = digits[i] - other.digits[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits[i] = diff;
    }
    return result;
}

// comparisons
bool HugeInteger::isEqualTo(const HugeInteger& other) const {
    for (int i = 0; i < maxDigits; i++) {
        if (digits[i] != other.digits[i]) return false;
    }
    return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger& other) const {
    return !isEqualTo(other);
}

bool HugeInteger::isGreaterThan(const HugeInteger& other) const {
    for (int i = 0; i < maxDigits; i++) {
        if (digits[i] > other.digits[i]) return true;
        if (digits[i] < other.digits[i]) return false;
    }
    return false;
}

bool HugeInteger::isLessThan(const HugeInteger& other) const {
    return other.isGreaterThan(*this);
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& other) const {
    return isGreaterThan(other) || isEqualTo(other);
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& other) const {
    return isLessThan(other) || isEqualTo(other);
}

bool HugeInteger::isZero() const {
    for (int i = 0; i < maxDigits; i++) {
        if (digits[i] != 0) return false;
    }
    return true;
}
