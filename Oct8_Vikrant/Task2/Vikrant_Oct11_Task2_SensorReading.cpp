#include "Vikrant_Oct11_Task2_SensorReading.h"

// Convert enum value to readable string
std::string severityToString(SeverityLevel level)
{
    switch (level)
    {
    case SeverityLevel::Low:
        return "Low";
    case SeverityLevel::Medium:
        return "Medium";
    case SeverityLevel::High:
        return "High";
    case SeverityLevel::Critical:
        return "Critical";
    default:
        return "Unknown";
    }
}

// Constructor
SensorReading::SensorReading(const std::string &name, double val, SeverityLevel level)
    : sensorName(name), value(val), severity(level) {}

// Display a single reading
void SensorReading::displayReading() const
{
    std::cout << "Sensor Name: " << sensorName
              << " | Value: " << value
              << " | Severity: " << severityToString(severity)
              << std::endl;
}

// Getters
std::string SensorReading::getSensorName() const { return sensorName; }
double SensorReading::getValue() const { return value; }
SeverityLevel SensorReading::getSeverityLevel() const { return severity; }

// Comparison for sorting (higher severity first)
bool SensorReading::operator<(const SensorReading &other) const
{
    return static_cast<int>(severity) > static_cast<int>(other.severity);
}
