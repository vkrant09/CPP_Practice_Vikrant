#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <string>

class DateAndTime {
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

    bool isLeapYear(unsigned int y) const;
    unsigned int daysInMonth(unsigned int m, unsigned int y) const;

public:
    DateAndTime(unsigned int m = 1, unsigned int d = 1, unsigned int y = 2000,
                unsigned int h = 0, unsigned int min = 0, unsigned int s = 0);

    void setDate(unsigned int m, unsigned int d, unsigned int y);
    void setTime(unsigned int h, unsigned int m, unsigned int s);

    void tick(); // increment 1 second

    std::string toStandardString() const;  // 12-hour clock with date
    std::string toUniversalString() const; // 24-hour clock with date
};

#endif
