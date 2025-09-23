#ifndef AIRLINE_H
#define AIRLINE_H

#include <array>
#include <string>

class Airline {
private:
    static const int capacity = 10;
    std::array<bool, capacity> seats;

public:
    Airline();

    bool assignSeat(int sectionChoice);
    void printBoardingPass(int seatNumber) const;

private:
    int findSeatInRange(int start, int end) const;
    int findAlternative(int sectionChoice) const;
};

#endif
