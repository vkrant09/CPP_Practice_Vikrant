#include "Vikrant_Oct11_Task2_DiagnosticReport.h"
#include <iostream>

int main()
{
    DiagnosticReport report;

    // Populate sample data
    report.addReading(SensorReading("EngineTemp", 105.0, SeverityLevel::High));
    report.addReading(SensorReading("OilPressure", 20.0, SeverityLevel::Medium));
    report.addReading(SensorReading("BrakeFluidLevel", 5.0, SeverityLevel::Critical));
    report.addReading(SensorReading("BatteryVoltage", 12.5, SeverityLevel::Low));
    report.addReading(SensorReading("CoolantTemp", 95.0, SeverityLevel::Medium));

    // Display all readings
    report.displayAllReadings();

    // Display severity distribution
    std::cout << "\n--- Severity Distribution ---\n";
    auto dist = report.getSeverityDistribution();
    for (const auto &pair : dist)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Sort by severity descending
    report.sortBySeverityDescending();
    std::cout << "\n--- Sorted by Severity (Descending) ---\n";
    report.displayAllReadings();

    // Filter and display only Critical readings
    auto criticalReadings = report.filterBySeverity(SeverityLevel::Critical);
    std::cout << "\n--- Critical Readings ---\n";
    for (const auto &r : criticalReadings)
    {
        r.displayReading();
    }

    // Search for a specific sensor
    std::string searchName = "BrakeFluidLevel";
    const SensorReading *found = report.findReadingByName(searchName);
    std::cout << "\n--- Search Result for " << searchName << " ---\n";
    if (found != nullptr)
    {
        found->displayReading();
    }
    else
    {
        std::cout << "Sensor not found.\n";
    }

    return 0;
}
