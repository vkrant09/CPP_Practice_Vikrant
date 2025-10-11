#include "Vikrant_Oct11_Task1_DiagnosticReport.h"
#include <iostream>

int main()
{
    DiagnosticReport report;

    // Adding sample readings as given in problem statement
    report.addReading(SensorReading("EngineTemp", 105.0, SeverityLevel::High));
    report.addReading(SensorReading("OilPressure", 20.0, SeverityLevel::Medium));
    report.addReading(SensorReading("BrakeFluidLevel", 5.0, SeverityLevel::Critical));
    report.addReading(SensorReading("BatteryVoltage", 12.5, SeverityLevel::Low));

    // Display all readings
    report.displayAllReadings();

    // Count readings with severity High or Critical
    int highOrCritical = report.countBySeverityOrHigher(SeverityLevel::High);
    std::cout << "\nReadings with severity HIGH or CRITICAL: " << highOrCritical << std::endl;

    return 0;
}
