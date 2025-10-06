#include "Vikrant_Oct6_Task1_CommissionEmployee.h"
#include <iostream>

// Constructor initializes the employee and validates inputs
CommissionEmployee::CommissionEmployee(const std::string& first, const std::string& last,
                                       const std::string& pan, double sales, double rate)
    : firstName(first), lastName(last), panNumber(pan), grossSales(0.0), commissionRate(0.0)
{
    // Instead of directly assigning, use setters to apply validation logic
    setGrossSales(sales);
    setCommissionRate(rate);
}

// Setter for first name
void CommissionEmployee::setFirstName(const std::string& first) {
    firstName = first;
}

// Getter for first name
std::string CommissionEmployee::getFirstName() const {
    return firstName;
}

// Setter for last name
void CommissionEmployee::setLastName(const std::string& last) {
    lastName = last;
}

// Getter for last name
std::string CommissionEmployee::getLastName() const {
    return lastName;
}

// Setter for PAN (no validation as PAN is a string)
void CommissionEmployee::setPanNumber(const std::string& pan) {
    panNumber = pan;
}

// Getter for PAN
std::string CommissionEmployee::getPanNumber() const {
    return panNumber;
}

// Validate and set gross sales
void CommissionEmployee::setGrossSales(double sales) {
    // Prevents negative sales values
    grossSales = (sales < 0.0) ? 0.0 : sales;
}

// Returns gross sales
double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

// Validate and set commission rate (must be between 0 and 1)
void CommissionEmployee::setCommissionRate(double rate) {
    commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
}

// Returns commission rate
double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

// Calculates total earnings = sales × commission
double CommissionEmployee::earnings() const {
    return grossSales * commissionRate;
}

// Displays all employee info in a readable format
void CommissionEmployee::display() const {
    std::cout << "Commission Employee: " << firstName << " " << lastName << '\n'
              << "PAN: " << panNumber << '\n'
              << "Gross Sales: " << grossSales << '\n'
              << "Commission Rate: " << commissionRate << '\n';
}
