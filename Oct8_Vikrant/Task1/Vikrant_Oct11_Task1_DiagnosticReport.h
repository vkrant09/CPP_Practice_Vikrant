#ifndef VIKRANT_OCT11_TASK1_DIAGNOSTICREPORT_H
#define VIKRANT_OCT11_TASK1_DIAGNOSTICREPORT_H

#include "Vikrant_Oct11_Task1_SensorReading.h"
#include <vector>

// Class representing a complete diagnostic report using composition
class DiagnosticReport
{
private:
    std::vector<SensorReading> readings;

public:
    // Add a new sensor reading
    void addReading(const SensorReading &reading);

    // Display all sensor readings
    void displayAllReadings() const;

    // Count readings with given severity or higher
    int countBySeverityOrHigher(SeverityLevel level) const;
};

#endif
