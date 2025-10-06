#ifndef VIKRANT_OCT6_TASK1_COMMISSIONEMPLOYEE_H
#define VIKRANT_OCT6_TASK1_COMMISSIONEMPLOYEE_H

#include <string>

// Base class representing an employee who earns commission on sales
class CommissionEmployee {
private:
    // Data members common for all commission-based employees
    std::string firstName;
    std::string lastName;
    std::string panNumber; // PAN acts as a unique ID for employees
    double grossSales;     // total sales made by employee
    double commissionRate; // percentage of sales earned as commission

public:
    // Constructor initializes all data members using the provided values
    CommissionEmployee(const std::string& first, const std::string& last,
                       const std::string& pan, double sales, double rate);

    // Setters and Getters (Encapsulation)
    void setFirstName(const std::string& first);
    std::string getFirstName() const;

    void setLastName(const std::string& last);
    std::string getLastName() const;

    void setPanNumber(const std::string& pan);
    std::string getPanNumber() const;

    void setGrossSales(double sales);
    double getGrossSales() const;

    void setCommissionRate(double rate);
    double getCommissionRate() const;

    // Calculates total earnings (gross sales × commission rate)
    double earnings() const;

    // Displays employee information
    void display() const;
};

#endif
