#include "airline.h"
#include <iostream>

int main() {
    Airline airline;
    int choice;

    while (true) {
        std::cout << "\nPlease type 1 for First Class\n";
        std::cout << "Please type 2 for Economy\n";
        std::cout << "Enter 0 to quit\n";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice == 1 || choice == 2) {
            airline.assignSeat(choice);
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
