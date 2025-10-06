#ifndef VIKRANT_OCT6_TASK1_BASEPLUSCOMMISSIONEMPLOYEE_H
#define VIKRANT_OCT6_TASK1_BASEPLUSCOMMISSIONEMPLOYEE_H

#include "Vikrant_Oct6_Task1_CommissionEmployee.h"

// Derived class adds a base salary to a commission-based employee
class BasePlusCommissionEmployee : public CommissionEmployee {
private:
    double baseSalary; // Fixed salary in addition to commission

public:
    // Constructor calls base class constructor and initializes base salary
    BasePlusCommissionEmployee(const std::string& first, const std::string& last,
                               const std::string& pan, double sales,
                               double rate, double salary);

    // Setter and getter for base salary
    void setBaseSalary(double salary);
    double getBaseSalary() const;

    // Redefine earnings to include base salary
    double earnings() const;

    // Redefine display to include base salary
    void display() const;
};

#endif
