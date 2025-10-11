#include "Vikrant_Oct11_Task1_SensorReading.h"

// Constructor definition
SensorReading::SensorReading(const std::string &name, double val, SeverityLevel level)
    : sensorName(name), value(val), severity(level) {}

// Method to display a single sensor reading
void SensorReading::displayReading() const
{
    std::cout << "Sensor Name: " << sensorName
              << " | Value: " << value
              << " | Severity: ";

    // Convert enum to readable text
    switch (severity)
    {
    case SeverityLevel::Low:
        std::cout << "Low";
        break;
    case SeverityLevel::Medium:
        std::cout << "Medium";
        break;
    case SeverityLevel::High:
        std::cout << "High";
        break;
    case SeverityLevel::Critical:
        std::cout << "Critical";
        break;
    }

    std::cout << std::endl;
}

// Getter for severity level
SeverityLevel SensorReading::getSeverityLevel() const
{
    return severity;
}
