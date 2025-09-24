#include "date.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

Date::Date(unsigned int m, unsigned int d, unsigned int y) {
    setDate(m, d, y);
}

// validate and set
void Date::setDate(unsigned int m, unsigned int d, unsigned int y) {
    if (m < 1 || m > 12) {
        throw std::invalid_argument("Month must be 1-12");
    }
    if (d < 1 || d > daysInMonth(m, y)) {
        throw std::invalid_argument("Invalid day for given month/year");
    }
    if (y < 1) {
        throw std::invalid_argument("Year must be positive");
    }

    month = m;
    day = d;
    year = y;
}

unsigned int Date::getMonth() const { return month; }
unsigned int Date::getDay() const { return day; }
unsigned int Date::getYear() const { return year; }

// helper: leap year check
bool Date::isLeapYear(unsigned int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// helper: number of days in given month
unsigned int Date::daysInMonth(unsigned int m, unsigned int y) const {
    static const unsigned int daysPerMonth[13] =
        {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (m == 2 && isLeapYear(y)) {
        return 29;
    }
    return daysPerMonth[m];
}

// go to the next calendar day
void Date::nextDay() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

// convert date to string like "MM/DD/YYYY"
std::string Date::toString() const {
    std::ostringstream out;
    out << std::setfill('0') << std::setw(2) << month << "/"
        << std::setw(2) << day << "/"
        << year;
    return out.str();
}
