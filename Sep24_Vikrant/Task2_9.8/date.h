#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;

    // helper to check days in a month
    unsigned int daysInMonth(unsigned int m, unsigned int y) const;
    bool isLeapYear(unsigned int y) const;

public:
    Date(unsigned int m = 1, unsigned int d = 1, unsigned int y = 2000);

    void setDate(unsigned int m, unsigned int d, unsigned int y);

    unsigned int getMonth() const;
    unsigned int getDay() const;
    unsigned int getYear() const;

    void nextDay(); // move to next calendar day
    std::string toString() const;
};

#endif
