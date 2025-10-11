#include "Vikrant_Oct11_Task2_DiagnosticReport.h"
#include <algorithm>
#include <iostream>

// Add a new reading
void DiagnosticReport::addReading(const SensorReading &reading)
{
    readings.push_back(reading);
}

// Display all readings
void DiagnosticReport::displayAllReadings() const
{
    std::cout << "\n--- Vehicle Diagnostic Report ---" << std::endl;
    for (const auto &reading : readings)
    {
        reading.displayReading();
    }
}

// Count readings with severity >= given level
int DiagnosticReport::countBySeverityOrHigher(SeverityLevel level) const
{
    int count = 0;
    for (const auto &r : readings)
    {
        if (static_cast<int>(r.getSeverityLevel()) >= static_cast<int>(level))
        {
            ++count;
        }
    }
    return count;
}

// Return readings that exactly match given severity
std::vector<SensorReading> DiagnosticReport::filterBySeverity(SeverityLevel level) const
{
    std::vector<SensorReading> result;
    for (const auto &r : readings)
    {
        if (r.getSeverityLevel() == level)
        {
            result.push_back(r);
        }
    }
    return result;
}

// Sort readings by severity descending
void DiagnosticReport::sortBySeverityDescending()
{
    std::sort(readings.begin(), readings.end());
}

// Generate a distribution map {Low:1, Medium:2, ...}
std::map<std::string, int> DiagnosticReport::getSeverityDistribution() const
{
    std::map<std::string, int> dist = {{"Low", 0}, {"Medium", 0}, {"High", 0}, {"Critical", 0}};
    for (const auto &r : readings)
    {
        ++dist[severityToString(r.getSeverityLevel())];
    }
    return dist;
}

// Find a reading by sensor name
const SensorReading *DiagnosticReport::findReadingByName(const std::string &name) const
{
    for (const auto &r : readings)
    {
        if (r.getSensorName() == name)
        {
            return &r;
        }
    }
    return nullptr;
}
