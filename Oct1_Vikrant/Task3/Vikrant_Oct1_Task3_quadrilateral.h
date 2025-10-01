#ifndef VIKRANT_OCT1_TASK3_QUADRILATERAL_H
#define VIKRANT_OCT1_TASK3_QUADRILATERAL_H

#include <iostream>
#include <string>

// -----------------------------
// Base Class: Quadrilateral
// -----------------------------
// Represents any generic 4-sided polygon.
// Holds side lengths and angles dynamically.
class Quadrilateral {
protected:
    float* sides;   // array of 4 side lengths
    float* angles;  // array of 4 angles in degrees
public:
    // Constructor, Copy Constructor, Assignment Operator, Destructor
    Quadrilateral(const float s[4], const float a[4]);
    Quadrilateral(const Quadrilateral& other);
    Quadrilateral& operator=(const Quadrilateral& other);
    virtual ~Quadrilateral();

    // Common operations
    virtual bool isValid() const;       // check if sum of angles = 360
    virtual float area() const;         // default area = 0 for generic quad
    float perimeter() const;            // sum of sides
    virtual std::string getType() const;// return shape type

    // Operator overloads
    bool operator==(const Quadrilateral& other) const; // compare areas
    friend std::ostream& operator<<(std::ostream& os, const Quadrilateral& q);
    float operator()() const;   // return perimeter using function call syntax
    operator float() const;     // cast object to area (float)
};

// -----------------------------
// Derived Classes (Inheritance Hierarchy)
// -----------------------------
class Trapezoid : public Quadrilateral {
public:
    Trapezoid(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;       // simple trapezoid area
    std::string getType() const override;
};

class Parallelogram : public Trapezoid {
public:
    Parallelogram(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;       // base * height using sine
    std::string getType() const override;
};

class Rectangle : public Parallelogram {
public:
    Rectangle(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;       // length * width
    std::string getType() const override;
};

class Square : public Rectangle {
public:
    Square(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;       // side^2
    std::string getType() const override;
};

#endif
