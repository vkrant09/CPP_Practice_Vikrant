#include "time.h"
#include <iomanip>
#include <sstream>

// constructor
Time::Time(unsigned int h, unsigned int m, unsigned int s) 
    : hour(0), minute(0), second(0) {
    setTime(h, m, s);
}

bool Time::setHour(unsigned int h) {
    if (h < 24) {
        hour = h;
        return true;
    }
    return false;
}

bool Time::setMinute(unsigned int m) {
    if (m < 60) {
        minute = m;
        return true;
    }
    return false;
}

bool Time::setSecond(unsigned int s) {
    if (s < 60) {
        second = s;
        return true;
    }
    return false;
}

bool Time::setTime(unsigned int h, unsigned int m, unsigned int s) {
    bool okH = setHour(h);
    bool okM = setMinute(m);
    bool okS = setSecond(s);
    return okH && okM && okS;
}

unsigned int Time::getHour() const { return hour; }
unsigned int Time::getMinute() const { return minute; }
unsigned int Time::getSecond() const { return second; }

std::string Time::toStandardString() const {
    std::ostringstream out;
    unsigned int stdHour = (hour % 12 == 0) ? 12 : hour % 12;
    out << stdHour << ":"
        << std::setfill('0') << std::setw(2) << minute << ":"
        << std::setfill('0') << std::setw(2) << second
        << (hour < 12 ? " AM" : " PM");
    return out.str();
}

std::string Time::toUniversalString() const {
    std::ostringstream out;
    out << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setw(2) << minute << ":"
        << std::setw(2) << second;
    return out.str();
}
