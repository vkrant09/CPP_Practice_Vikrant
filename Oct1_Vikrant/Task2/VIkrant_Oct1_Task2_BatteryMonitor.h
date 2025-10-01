#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <iostream>
#include <string>

class BatteryMonitor {
private:
    std::string scooterID;
    int chargeCycles;
    float batteryCapacity;     // current capacity
    float originalCapacity;    // original capacity
    bool isActive;
    int* tripDistances;        // dynamic array
    int tripCount;

public:
    // Constructor
    BatteryMonitor(const std::string& id, int cycles,
                   float currentCap, float originalCap,
                   bool active, int trips);

    // Copy constructor (deep copy)
    BatteryMonitor(const BatteryMonitor& other);

    // Assignment operator (deep copy with self-assignment check)
    BatteryMonitor& operator=(const BatteryMonitor& other);

    // Destructor
    ~BatteryMonitor();

    // Operator overloads
    bool operator>(const BatteryMonitor& other) const;
    bool operator<(const BatteryMonitor& other) const;
    BatteryMonitor& operator+=(int extraCycles);   // simulate degradation
    int& operator[](int index);                    // subscript
    bool operator!() const;                        // inactive check
    friend std::ostream& operator<<(std::ostream& os, const BatteryMonitor& bm);

    // Getters for testing
    std::string getID() const { return scooterID; }
    int getTripCount() const { return tripCount; }
};

#endif
