#include "VIkrant_Oct1_Task2_BatteryMonitor.h"

#include <iostream>

int main() {
    // Create scooters with trips
    BatteryMonitor s1("SCT101", 300, 4.0, 5.0, true, 3); // 80% health
    BatteryMonitor s2("SCT202", 150, 3.5, 5.0, true, 2); // 70% health

    // Populate trips
    s1[0] = 12; s1[1] = 18; s1[2] = 25;
    s2[0] = 10; s2[1] = 15;

    // Display
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    // Compare health
    if (s1 > s2) {
        std::cout << "Scooter " << s1.getID() << " has better health.\n";
    } else {
        std::cout << "Scooter " << s2.getID() << " has better health.\n";
    }

    // Simulate degradation
    s1 += 50;
    std::cout << "After 50 cycles, " << s1 << std::endl;

    // Check inactive
    if (!s1) {
        std::cout << s1.getID() << " is inactive.\n";
    }

    // Copy and verify deep copy
    BatteryMonitor s3 = s1; // copy constructor
    std::cout << "Copied scooter (s3): " << s3 << std::endl;

    s3[0] = 99; // change trip of s3
    std::cout << "After modifying s3 trips:\n";
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s3: " << s3 << std::endl;

    return 0;
}
