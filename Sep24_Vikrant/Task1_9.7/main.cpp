#include "time.h"
#include <iostream>

int main() {
    // Test: incrementing into the next minute
    Time t1(10, 59, 58);
    std::cout << "Testing increment into next minute:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << t1.toStandardString() << "\n";
        t1.tick();
    }

    // Test: incrementing into the next hour
    Time t2(1, 59, 58);
    std::cout << "\nTesting increment into next hour:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << t2.toStandardString() << "\n";
        t2.tick();
    }

    // Test: incrementing into the next day
    Time t3(23, 59, 58);
    std::cout << "\nTesting increment into next day:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << t3.toStandardString() << "\n";
        t3.tick();
    }

    return 0;
}
