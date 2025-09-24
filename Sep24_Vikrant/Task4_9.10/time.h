#ifndef TIME_H
#define TIME_H

#include <string>

class Time {
private:
    unsigned int hour;   // 0–23
    unsigned int minute; // 0–59
    unsigned int second; // 0–59

public:
    Time(unsigned int h = 0, unsigned int m = 0, unsigned int s = 0);

    // return true if valid, false otherwise
    bool setHour(unsigned int h);
    bool setMinute(unsigned int m);
    bool setSecond(unsigned int s);
    bool setTime(unsigned int h, unsigned int m, unsigned int s);

    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

    std::string toStandardString() const;
    std::string toUniversalString() const;
};

#endif
