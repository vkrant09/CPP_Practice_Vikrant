#include "Vikrant_Oct11_Task1_DiagnosticReport.h"
#include <iostream>

// Add a new reading to the report
void DiagnosticReport::addReading(const SensorReading &reading)
{
    readings.push_back(reading);
}

// Display all readings in the report
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
    for (const auto &reading : readings)
    {
        if (static_cast<int>(reading.getSeverityLevel()) >= static_cast<int>(level))
        {
            ++count;
        }
    }
    return count;
}
