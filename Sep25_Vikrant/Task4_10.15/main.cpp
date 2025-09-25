#include "flight.h"
#include <iostream>

int main() {
    std::cout << "Air Traffic Control Simulator\n\n";

    Flight f1("Delta", "DL404", "Boeing 737", "ATL", "LAX", "08:00", "10:30");
    Flight f2("United", "UA101", "Airbus A320", "ORD", "JFK", "09:15", "12:00");
    Flight f3("American", "AA550", "Boeing 777", "DFW", "MIA", "07:45", "11:20");

    std::cout << f1.toString() << "\n";
    std::cout << f2.toString() << "\n";
    std::cout << f3.toString() << "\n";

    f1.changeAltitude(20000);
    f2.reduceSpeed(250);
    f3.beginLandingApproach();

    std::cout << "\nUpdated Flight Info:\n";
    std::cout << f1.toString() << "\n";
    std::cout << f2.toString() << "\n";
    std::cout << f3.toString() << "\n";

    return 0;
}
