#include <iostream>
#include <iomanip>  // for std::fixed and std::setprecision
using namespace std;

int main()
{
    const int SIZE = 10;

    // (a) Declare and initialize array numbers with values 0.0, 1.1, ..., 9.9
    double numbers[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4,
                            5.5, 6.6, 7.7, 8.8, 9.9};

    // (b) Declare a pointer nPtr that points to a double
    double* nPtr = nullptr;

    cout << fixed << setprecision(1); // print with one decimal place

    // (c) Print elements using array subscript notation
    cout << "(c) Print with array subscript notation:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "numbers[" << i << "] = " << numbers[i] << "\n";
    }

    // (d) Assign starting address of numbers to nPtr
    nPtr = numbers;          // array name is address of first element
    // OR:
    nPtr = &numbers[0];      // explicitly take address of first element

    // (e) Print using pointer/offset notation with pointer nPtr
    cout << "\n(e) Print with pointer/offset (nPtr + i):\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "*(nPtr + " << i << ") = " << *(nPtr + i) << "\n";
    }

    // (f) Print using pointer/offset notation with array name
    cout << "\n(f) Print with pointer/offset (numbers + i):\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "*(numbers + " << i << ") = " << *(numbers + i) << "\n";
    }

    // (g) Print using pointer/subscript notation with nPtr
    cout << "\n(g) Print with pointer/subscript (nPtr[i]):\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "nPtr[" << i << "] = " << nPtr[i] << "\n";
    }

    // (h) Refer to 4th element (index 3) in 4 different ways
    cout << "\n(h) Fourth element (index 3):\n";
    cout << "numbers[3] = " << numbers[3] << "\n";
    cout << "*(numbers + 3) = " << *(numbers + 3) << "\n";
    cout << "nPtr[3] = " << nPtr[3] << "\n";
    cout << "*(nPtr + 3) = " << *(nPtr + 3) << "\n";

    // (i) If nPtr points to beginning, what is nPtr + 8?
    nPtr = numbers; // reset pointer to beginning
    cout << "\n(i) nPtr + 8 points to address: " << (nPtr + 8)
         << " value at that location = " << *(nPtr + 8) << "\n";

    // (j) If nPtr points to numbers[5], after nPtr -= 4?
    nPtr = &numbers[5]; // point to element 5
    nPtr -= 4;          // move pointer back 4 elements
    cout << "\n(j) Now nPtr points to address: " << nPtr
         << " value at that location = " << *nPtr << "\n";

    return 0;
}
