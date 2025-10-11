#ifndef VIKRANT_OCT11_TASK2_DIAGNOSTICREPORT_H
#define VIKRANT_OCT11_TASK2_DIAGNOSTICREPORT_H

#include "Vikrant_Oct11_Task2_SensorReading.h"
#include <vector>
#include <map>

// Class representing full diagnostic report
class DiagnosticReport
{
private:
    std::vector<SensorReading> readings;

public:
    // Add reading
    void addReading(const SensorReading &reading);

    // Display all readings
    void displayAllReadings() const;

    // Count readings with given severity or higher
    int countBySeverityOrHigher(SeverityLevel level) const;

    // Filter readings by exact severity
    std::vector<SensorReading> filterBySeverity(SeverityLevel level) const;

    // Sort readings by severity (descending)
    void sortBySeverityDescending();

    // Get severity distribution map
    std::map<std::string, int> getSeverityDistribution() const;

    // Find a reading by sensor name
    const SensorReading *findReadingByName(const std::string &name) const;
};

#endif
