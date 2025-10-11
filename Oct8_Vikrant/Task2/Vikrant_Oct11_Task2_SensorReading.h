#ifndef VIKRANT_OCT11_TASK2_SENSORREADING_H
#define VIKRANT_OCT11_TASK2_SENSORREADING_H

#include <string>
#include <iostream>

// Enum class for severity levels
enum class SeverityLevel
{
    Low,
    Medium,
    High,
    Critical
};

// Utility: Convert enum to readable string
std::string severityToString(SeverityLevel level);

// Class representing one sensor reading
class SensorReading
{
private:
    std::string sensorName;
    double value;
    SeverityLevel severity;

public:
    // Constructor
    SensorReading(const std::string &name, double val, SeverityLevel level);

    // Display a single sensor reading
    void displayReading() const;

    // Getters
    std::string getSensorName() const;
    double getValue() const;
    SeverityLevel getSeverityLevel() const;

    // Comparison (used for sorting)
    bool operator<(const SensorReading &other) const;
};

#endif
