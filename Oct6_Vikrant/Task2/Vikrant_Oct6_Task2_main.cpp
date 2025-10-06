#include "Vikrant_Oct6_Task2_Student.h"
#include <iostream>

int main() {
    // sample students to test the hierarchy

    Freshman s1("Rohan", 101);
    Senior s2("Meena", 104);
    MastersStudent s3("Amit", 201);
    DoctoralStudent s4("Priya", 301);

    // displaying info for each
    std::cout << "--- Student Info Display ---" << std::endl;
    s1.displayInfo();
    s2.displayInfo();
    s3.displayInfo();
    s4.displayInfo();

    // using base class pointer to show polymorphism
    Student* basePtr = &s4;
    basePtr->displayInfo();

    return 0;
}
