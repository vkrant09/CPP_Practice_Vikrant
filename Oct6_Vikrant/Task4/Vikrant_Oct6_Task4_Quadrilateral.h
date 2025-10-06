#ifndef VIKRANT_OCT6_TASK4_QUADRILATERAL_H
#define VIKRANT_OCT6_TASK4_QUADRILATERAL_H

#include <string>

// Base class for all quadrilaterals
class Quadrilateral {
protected:
    std::string shapeName;

public:
    Quadrilateral(const std::string& name);
    virtual void displayInfo() const;
    virtual ~Quadrilateral();
};

// Derived class - Trapezoid
class Trapezoid : public Quadrilateral {
public:
    Trapezoid();
    void displayInfo() const override;
};

// Derived from Trapezoid - Parallelogram
class Parallelogram : public Trapezoid {
public:
    Parallelogram();
    void displayInfo() const override;
};

// Derived from Parallelogram - Rectangle
class Rectangle : public Parallelogram {
public:
    Rectangle();
    void displayInfo() const override;
};

// Derived from Rectangle - Square
class Square : public Rectangle {
public:
    Square();
    void displayInfo() const override;
};

#endif
