#include "dateandtime.h"
#include <iostream>

int main() {
    try {
        // start near midnight
        DateAndTime dt(12, 31, 2023, 23, 59, 58);

        std::cout << "Testing tick into next day:\n";
        for (int i = 0; i < 5; i++) {
            std::cout << dt.toStandardString() << " | "
                      << dt.toUniversalString() << "\n";
            dt.tick();
        }

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
