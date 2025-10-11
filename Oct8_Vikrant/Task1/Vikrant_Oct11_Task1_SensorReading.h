#ifndef VIKRANT_OCT11_TASK1_SENSORREADING_H
#define VIKRANT_OCT11_TASK1_SENSORREADING_H

#include <string>
#include <iostream>

// Enum class for Severity Levels
enum class SeverityLevel
{
    Low,
    Medium,
    High,
    Critical
};

// Class representing an individual sensor reading
class SensorReading
{
private:
    std::string sensorName;
    double value;
    SeverityLevel severity;

public:
    // Constructor to initialize all attributes
    SensorReading(const std::string &name, double val, SeverityLevel level);

    // Display a single sensor reading
    void displayReading() const;

    // Retrieve the severity level
    SeverityLevel getSeverityLevel() const;
};

#endif
