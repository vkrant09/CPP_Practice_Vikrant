#include "dateandtime.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

// constructor
DateAndTime::DateAndTime(unsigned int m, unsigned int d, unsigned int y,
                         unsigned int h, unsigned int min, unsigned int s) {
    setDate(m, d, y);
    setTime(h, min, s);
}

// validate and set date
void DateAndTime::setDate(unsigned int m, unsigned int d, unsigned int y) {
    if (m < 1 || m > 12) {
        throw std::invalid_argument("Month must be 1-12");
    }
    if (y < 1) {
        throw std::invalid_argument("Year must be positive");
    }
    if (d < 1 || d > daysInMonth(m, y)) {
        throw std::invalid_argument("Invalid day for given month/year");
    }
    month = m;
    day = d;
    year = y;
}

// validate and set time
void DateAndTime::setTime(unsigned int h, unsigned int m, unsigned int s) {
    if (h >= 24 || m >= 60 || s >= 60) {
        throw std::invalid_argument("Invalid time values");
    }
    hour = h;
    minute = m;
    second = s;
}

// leap year check
bool DateAndTime::isLeapYear(unsigned int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// days in a month
unsigned int DateAndTime::daysInMonth(unsigned int m, unsigned int y) const {
    static const unsigned int daysPerMonth[13] =
        {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) {
        return 29;
    }
    return daysPerMonth[m];
}

// tick forward one second
void DateAndTime::tick() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
                // next day
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
        }
    }
}

// standard string: "MM/DD/YYYY HH:MM:SS AM/PM"
std::string DateAndTime::toStandardString() const {
    std::ostringstream out;
    unsigned int stdHour = (hour % 12 == 0) ? 12 : hour % 12;
    out << std::setfill('0') << std::setw(2) << month << "/"
        << std::setw(2) << day << "/" << year << " "
        << stdHour << ":" << std::setw(2) << minute
        << ":" << std::setw(2) << second
        << (hour < 12 ? " AM" : " PM");
    return out.str();
}

// universal string: "MM/DD/YYYY HH:MM:SS"
std::string DateAndTime::toUniversalString() const {
    std::ostringstream out;
    out << std::setfill('0') << std::setw(2) << month << "/"
        << std::setw(2) << day << "/" << year << " "
        << std::setw(2) << hour << ":" << std::setw(2) << minute
        << ":" << std::setw(2) << second;
    return out.str();
}
