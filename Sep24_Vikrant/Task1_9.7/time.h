#ifndef TIME_H
#define TIME_H

#include <string>

class Time {
private:
    unsigned int hour;   // 0–23
    unsigned int minute; // 0–59
    unsigned int second; // 0–59

public:
    Time(); // default 00:00:00
    Time(unsigned int h, unsigned int m, unsigned int s);

    void setTime(unsigned int h, unsigned int m, unsigned int s);

    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

    void tick(); // increment by one second

    std::string toStandardString() const;
};

#endif
