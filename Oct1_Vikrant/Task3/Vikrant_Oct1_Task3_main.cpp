#include "Vikrant_Oct1_Task3_quadrilateral.h"
#include <iostream>

int main() {
    // Example side lengths and angles for each shape
    float sqSides[4] = {5,5,5,5}, sqAngles[4] = {90,90,90,90};
    float rectSides[4] = {6,4,6,4}, rectAngles[4] = {90,90,90,90};
    float paraSides[4] = {6,4,6,4}, paraAngles[4] = {110,70,110,70};
    float trapSides[4] = {6,5,4,3}, trapAngles[4] = {100,80,100,80};
    float quadSides[4] = {3,4,5,6}, quadAngles[4] = {90,90,90,90};

    // Create objects for all shapes
    Square sq(sqSides, sqAngles);
    Rectangle rect(rectSides, rectAngles);
    Parallelogram para(paraSides, paraAngles);
    Trapezoid trap(trapSides, trapAngles);
    Quadrilateral quad(quadSides, quadAngles);

    // Store base class pointers to demonstrate polymorphism
    Quadrilateral* shapes[5] = {&sq, &rect, &para, &trap, &quad};

    // Display properties of each shape
    for (int i = 0; i < 5; i++) {
    std::cout << *shapes[i] << std::endl;
    std::cout << "Valid? " << (shapes[i]->isValid() ? "Yes" : "No") << std::endl;
    std::cout << "Area: " << float(*shapes[i]) << std::endl;      // correct
    std::cout << "Perimeter: " << (*shapes[i])() << std::endl;    // correct
    std::cout << std::endl;
}


    // Compare areas of square and rectangle
    std::cout << "Rectangle and Square same area? "
              << ((rect == sq) ? "Yes" : "No") << std::endl;

    return 0;
}
