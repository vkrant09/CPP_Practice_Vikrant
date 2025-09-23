#include "airline.h"
#include <iostream>

Airline::Airline() {
    seats.fill(false); // all seats initially empty
}

int Airline::findSeatInRange(int start, int end) const {
    for (int i = start; i <= end; i++) {
        if (!seats[i]) {
            return i;
        }
    }
    return -1; // no free seat
}

int Airline::findAlternative(int sectionChoice) const {
    if (sectionChoice == 1) {
        return findSeatInRange(5, 9); // try economy
    } else {
        return findSeatInRange(0, 4); // try first class
    }
}

bool Airline::assignSeat(int sectionChoice) {
    int seat = -1;

    if (sectionChoice == 1) {
        seat = findSeatInRange(0, 4); // first class
    } else if (sectionChoice == 2) {
        seat = findSeatInRange(5, 9); // economy
    }

    if (seat != -1) {
        seats[seat] = true;
        printBoardingPass(seat);
        return true;
    }

    // section full → try alternative
    int altSeat = findAlternative(sectionChoice);
    if (altSeat != -1) {
        std::cout << "Requested section full. "
                  << "Would you like to be seated in the other section? (y/n): ";
        char response;
        std::cin >> response;
        if (response == 'y' || response == 'Y') {
            seats[altSeat] = true;
            printBoardingPass(altSeat);
            return true;
        } else {
            std::cout << "Next flight leaves in 3 hours.\n";
            return false;
        }
    }

    // plane full
    std::cout << "Sorry, the plane is completely full.\n";
    return false;
}

void Airline::printBoardingPass(int seatNumber) const {
    std::string section = (seatNumber < 5) ? "First Class" : "Economy";
    std::cout << "Boarding Pass → Seat " << (seatNumber + 1)
              << " (" << section << ")\n";
}
