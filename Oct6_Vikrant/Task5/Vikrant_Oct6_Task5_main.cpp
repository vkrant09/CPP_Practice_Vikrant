#include "Vikrant_Oct6_Task5_Package.h"
#include <iostream>

int main() {
    // i created different types of package objects for testing

    TwoDayPackage twoDay(
        "Amit", "123 MG Road", "Mumbai", "MH", "400001",
        "Neha", "55 Civil Lines", "Delhi", "DL", "110001",
        10.5, 0.5, 2.0);

    OvernightPackage overnight(
        "Rohit", "45 Hill Street", "Pune", "MH", "411001",
        "Priya", "88 Nehru Nagar", "Bangalore", "KA", "560001",
        5.0, 0.6, 0.25);

    std::cout << "--- Package Cost Calculation ---" << std::endl;
    twoDay.displayInfo();
    overnight.displayInfo();

    // using base pointer to demonstrate polymorphism
    Package* basePtr = &overnight;
    std::cout << "Accessing via base class pointer -> Cost: $" << basePtr->calculateCost() << std::endl;

    return 0;
}
