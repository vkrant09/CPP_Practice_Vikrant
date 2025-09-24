#include "time.h"
#include <iostream>

int main() {
    Time t;

    std::cout << "Initial time: " << t.toUniversalString() << "\n";

    if (!t.setHour(25)) {
        std::cout << "Error: invalid hour (25)\n";
    }
    if (!t.setMinute(70)) {
        std::cout << "Error: invalid minute (70)\n";
    }
    if (!t.setSecond(99)) {
        std::cout << "Error: invalid second (99)\n";
    }

    std::cout << "After invalid attempts: " << t.toUniversalString() << "\n";

    if (t.setTime(13, 45, 30)) {
        std::cout << "Time set successfully!\n";
    } else {
        std::cout << "Error: could not set time.\n";
    }

    std::cout << "Standard: " << t.toStandardString() << "\n";
    std::cout << "Universal: " << t.toUniversalString() << "\n";

    return 0;
}
