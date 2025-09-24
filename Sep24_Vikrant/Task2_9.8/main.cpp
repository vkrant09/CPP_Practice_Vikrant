#include "date.h"
#include <iostream>

int main() {
    try {
        // Test: increment into next month
        Date d1(1, 30, 2023); 
        std::cout << "Incrementing into next month:\n";
        for (int i = 0; i < 3; i++) {
            std::cout << d1.toString() << "\n";
            d1.nextDay();
        }

        // Test: increment into next year
        Date d2(12, 30, 2023);
        std::cout << "\nIncrementing into next year:\n";
        for (int i = 0; i < 5; i++) {
            std::cout << d2.toString() << "\n";
            d2.nextDay();
        }

        // Test: leap year transition
        Date d3(2, 28, 2024); 
        std::cout << "\nLeap year check:\n";
        for (int i = 0; i < 3; i++) {
            std::cout << d3.toString() << "\n";
            d3.nextDay();
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
