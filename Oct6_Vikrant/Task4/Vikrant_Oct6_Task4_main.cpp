#include "Vikrant_Oct6_Task4_Quadrilateral.h"
#include <iostream>

int main() {
    // creating one object for each type of shape
    Trapezoid t;
    Parallelogram p;
    Rectangle r;
    Square s;

    std::cout << "--- Quadrilateral Hierarchy Demo ---" << std::endl;

    // calling display function for each shape
    t.displayInfo();
    p.displayInfo();
    r.displayInfo();
    s.displayInfo();

    // showing polymorphism (base pointer pointing to derived)
    Quadrilateral* basePtr = &s;
    basePtr->displayInfo();

    return 0;
}
