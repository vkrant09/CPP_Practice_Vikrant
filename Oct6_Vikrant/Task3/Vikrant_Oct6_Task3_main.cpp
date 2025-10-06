#include "Vikrant_Oct6_Task3_Shape.h"
#include <iostream>

int main() {
    //  created a few objects from both 2D and 3D shape categories

    Circle c;
    Rectangle r;
    Sphere s;
    Cube cube;
    Cone cone;

    std::cout << "--- Displaying Shapes Info ---" << std::endl;

    // calling display functions
    c.displayInfo();
    r.displayInfo();
    s.displayInfo();
    cube.displayInfo();
    cone.displayInfo();

    // showing polymorphism concept using base class pointer
    Shape* shapePtr = &s;
    shapePtr->displayInfo();

    return 0;
}
