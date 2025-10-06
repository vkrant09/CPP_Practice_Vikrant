#include "Vikrant_Oct6_Task4_Quadrilateral.h"
#include <iostream>

// base constructor
Quadrilateral::Quadrilateral(const std::string& name) : shapeName(name) {}

Quadrilateral::~Quadrilateral() {}

void Quadrilateral::displayInfo() const {
    std::cout << "Shape: " << shapeName << std::endl;
}

// trapezoid class
Trapezoid::Trapezoid() : Quadrilateral("Trapezoid") {}

void Trapezoid::displayInfo() const {
    std::cout << "This is a Trapezoid (has one pair of parallel sides)" << std::endl;
}

// parallelogram class
Parallelogram::Parallelogram() : Trapezoid() {
    shapeName = "Parallelogram";
}

void Parallelogram::displayInfo() const {
    std::cout << "This is a Parallelogram (two pairs of parallel sides)" << std::endl;
}

// rectangle class
Rectangle::Rectangle() : Parallelogram() {
    shapeName = "Rectangle";
}

void Rectangle::displayInfo() const {
    std::cout << "This is a Rectangle (right angles and opposite sides equal)" << std::endl;
}

// square class
Square::Square() : Rectangle() {
    shapeName = "Square";
}

void Square::displayInfo() const {
    std::cout << "This is a Square (all sides equal and all angles 90 degrees)" << std::endl;
}
