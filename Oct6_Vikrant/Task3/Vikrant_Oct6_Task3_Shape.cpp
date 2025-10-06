#include "Vikrant_Oct6_Task3_Shape.h"
#include <iostream>

// base class constructor
Shape::Shape(const std::string& name) : shapeName(name) {}

Shape::~Shape() {}

void Shape::displayInfo() const {
    std::cout << "Shape: " << shapeName << std::endl;
}

// ---------------- 2D ----------------
TwoDimensionalShape::TwoDimensionalShape(const std::string& name) : Shape(name) {}

void TwoDimensionalShape::displayInfo() const {
    std::cout << "2D Shape: " << shapeName << std::endl;
}

Circle::Circle() : TwoDimensionalShape("Circle") {}

void Circle::displayInfo() const {
    std::cout << "This is a Circle (2D Shape)" << std::endl;
}

Rectangle::Rectangle() : TwoDimensionalShape("Rectangle") {}

void Rectangle::displayInfo() const {
    std::cout << "This is a Rectangle (2D Shape)" << std::endl;
}

Triangle::Triangle() : TwoDimensionalShape("Triangle") {}

void Triangle::displayInfo() const {
    std::cout << "This is a Triangle (2D Shape)" << std::endl;
}

Square::Square() : TwoDimensionalShape("Square") {}

void Square::displayInfo() const {
    std::cout << "This is a Square (2D Shape)" << std::endl;
}

// ---------------- 3D ----------------
ThreeDimensionalShape::ThreeDimensionalShape(const std::string& name) : Shape(name) {}

void ThreeDimensionalShape::displayInfo() const {
    std::cout << "3D Shape: " << shapeName << std::endl;
}

Sphere::Sphere() : ThreeDimensionalShape("Sphere") {}

void Sphere::displayInfo() const {
    std::cout << "This is a Sphere (3D Shape)" << std::endl;
}

Cube::Cube() : ThreeDimensionalShape("Cube") {}

void Cube::displayInfo() const {
    std::cout << "This is a Cube (3D Shape)" << std::endl;
}

Cylinder::Cylinder() : ThreeDimensionalShape("Cylinder") {}

void Cylinder::displayInfo() const {
    std::cout << "This is a Cylinder (3D Shape)" << std::endl;
}

Cone::Cone() : ThreeDimensionalShape("Cone") {}

void Cone::displayInfo() const {
    std::cout << "This is a Cone (3D Shape)" << std::endl;
}

