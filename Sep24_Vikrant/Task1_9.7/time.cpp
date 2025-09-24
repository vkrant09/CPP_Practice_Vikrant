#include "time.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

Time::Time() : hour(0), minute(0), second(0) {}

Time::Time(unsigned int h, unsigned int m, unsigned int s) {
    setTime(h, m, s);
}

void Time::setTime(unsigned int h, unsigned int m, unsigned int s) {
    if (h >= 24 || m >= 60 || s >= 60) {
        throw std::invalid_argument("Invalid time values");
    }
    hour = h;
    minute = m;
    second = s;
}

unsigned int Time::getHour() const { return hour; }
unsigned int Time::getMinute() const { return minute; }
unsigned int Time::getSecond() const { return second; }

void Time::tick() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0; // next day
            }
        }
    }
}

std::string Time::toStandardString() const {
    std::ostringstream output;
    unsigned int stdHour = (hour % 12 == 0) ? 12 : hour % 12;
    output << stdHour << ":"
           << std::setfill('0') << std::setw(2) << minute << ":"
           << std::setfill('0') << std::setw(2) << second
           << (hour < 12 ? " AM" : " PM");
    return output.str();
}
