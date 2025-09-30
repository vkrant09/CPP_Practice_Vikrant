#include <iostream>
using namespace std;

int main() {
    double number1 = 7.3;
    double number2 = 0.0;
    char* ptr;               // unused here but given in question
    char s1[100] = "Hello";
    char s2[100] = "World";

    // (a) declare a double pointer
    double* fPtr = nullptr;

    // (b) assign address of number1
    fPtr = &number1;

    // (c) print value pointed to by fPtr
    cout << "(c) *fPtr = " << *fPtr << endl;

    // (d) assign value of *fPtr to number2
    number2 = *fPtr;

    // (e) print number2
    cout << "(e) number2 = " << number2 << endl;

    // (f) print address of number1
    cout << "(f) &number1 = " << &number1 << endl;

    // (g) print address stored in fPtr
    cout << "(g) fPtr = " << fPtr << endl;

    return 0;
}
