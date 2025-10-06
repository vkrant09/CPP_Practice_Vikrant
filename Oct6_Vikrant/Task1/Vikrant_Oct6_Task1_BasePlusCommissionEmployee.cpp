#include "Vikrant_Oct6_Task1_BasePlusCommissionEmployee.h"
#include <iostream>

// Constructor initializes both base and derived class members
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first,
                                                       const std::string& last,
                                                       const std::string& pan,
                                                       double sales, double rate,
                                                       double salary)
    : CommissionEmployee(first, last, pan, sales, rate), baseSalary(0.0)
{
    setBaseSalary(salary);
}

// Setter ensures base salary is non-negative
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = (salary < 0.0) ? 0.0 : salary;
}

// Getter returns the fixed base salary
double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

// Calculates total earnings = base salary + commission earnings
double BasePlusCommissionEmployee::earnings() const {
    return getBaseSalary() + CommissionEmployee::earnings();
}

// Display both base and derived class information
void BasePlusCommissionEmployee::display() const {
    // Reuse base class display to avoid code repetition
    CommissionEmployee::display();
    std::cout << "Base Salary: " << baseSalary << '\n'
              << "Total Earnings: " << earnings() << '\n';
}
