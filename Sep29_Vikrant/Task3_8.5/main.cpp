#include <iostream>
using namespace std;

// (b) prototype
void exchange(double* x, double* y);

// (d) prototype
int evaluate(int x, int (*poly)(int));

// simple polynomial function for testing (f(x) = x^2)
int square(int num) {
    return num * num;
}

int main() {
    // test exchange
    double a = 3.5, b = 7.2;
    cout << "Before exchange: a=" << a << " b=" << b << endl;
    exchange(&a, &b);
    cout << "After exchange:  a=" << a << " b=" << b << endl;

    // test evaluate
    int value = 5;
    cout << "Square of " << value << " = " << evaluate(value, square) << endl;

    // test vowel arrays
    char vowel1[6] = {'A','E','I','O','U','\0'};
    char vowel2[] = "AEIOU";
    cout << "Vowels 1: " << vowel1 << endl;
    cout << "Vowels 2: " << vowel2 << endl;

    return 0;
}

// (a) header + definition
void exchange(double* x, double* y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}

// (c) header + definition
int evaluate(int x, int (*poly)(int)) {
    return poly(x); // call the function pointer
}
