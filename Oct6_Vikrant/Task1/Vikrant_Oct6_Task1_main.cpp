#include <iostream>
#include "Vikrant_Oct6_Task1_BasePlusCommissionEmployee.h"

int main() {
    // Create a commission-only employee
    CommissionEmployee emp1("Vikrant", "Pundir", "ABCPN1234", 5000.0, 0.06);

    // Create a base + commission employee
    BasePlusCommissionEmployee emp2("Arjun", "Singh", "ARJPN6789", 8000.0, 0.05, 1200.0);

    // Display information for the first employee
    std::cout << "--- Commission Employee Details ---\n";
    emp1.display();
    std::cout << "Earnings: " << emp1.earnings() << "\n\n";

    // Display information for the derived employee
    std::cout << "--- Base Plus Commission Employee Details ---\n";
    emp2.display();

    

    return 0;
}
