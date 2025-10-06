#ifndef VIKRANT_OCT6_TASK3_SHAPE_H
#define VIKRANT_OCT6_TASK3_SHAPE_H

#include <string>

// base class for all shapes
class Shape {
protected:
    std::string shapeName;

public:
    Shape(const std::string& name);
    virtual void displayInfo() const;
    virtual ~Shape();
};

// class for 2D shapes like circle, rectangle etc.
class TwoDimensionalShape : public Shape {
public:
    TwoDimensionalShape(const std::string& name);
    void displayInfo() const override;
};

// class for 3D shapes like sphere, cube etc.
class ThreeDimensionalShape : public Shape {
public:
    ThreeDimensionalShape(const std::string& name);
    void displayInfo() const override;
};

// ---------------- 2D SHAPES ----------------
class Circle : public TwoDimensionalShape {
public:
    Circle();
    void displayInfo() const override;
};

class Rectangle : public TwoDimensionalShape {
public:
    Rectangle();
    void displayInfo() const override;
};

class Triangle : public TwoDimensionalShape {
public:
    Triangle();
    void displayInfo() const override;
};

class Square : public TwoDimensionalShape {
public:
    Square();
    void displayInfo() const override;
};

// ---------------- 3D SHAPES ----------------
class Sphere : public ThreeDimensionalShape {
public:
    Sphere();
    void displayInfo() const override;
};

class Cube : public ThreeDimensionalShape {
public:
    Cube();
    void displayInfo() const override;
};

class Cylinder : public ThreeDimensionalShape {
public:
    Cylinder();
    void displayInfo() const override;
};

class Cone : public ThreeDimensionalShape {
public:
    Cone();
    void displayInfo() const override;
};

#endif
