#ifndef FLEETVEHICLE_H
#define FLEETVEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class FleetVehicle {
private:
    int vehicleID;
    float fuelLevel;
    double distanceTravelled;
    char status; // 'A' for Active, 'I' for Inactive
    bool isAvailable;
    string driverName;

public:
    // Default constructor
    FleetVehicle();

    // Parameterized constructor
    FleetVehicle(int id, float fuel, double distance, char stat, bool available, string driver);

    // Destructor
    ~FleetVehicle();

    // Getters
    int getVehicleID() const;
    float getFuelLevel() const;
    double getDistanceTravelled() const;
    char getStatus() const;
    bool getAvailability() const;
    string getDriverName() const;

    // Setters
    void setVehicleID(int id);
    void setFuelLevel(float fuel);
    void setDistanceTravelled(double distance);
    void setStatus(char stat);
    void setAvailability(bool available);
    void setDriverName(string name);

    // Member functions
    void updateStatus();     // Update based on fuel and availability
    void displayInfo() const; // Print vehicle details
};

// Global functions
void assignDriver(FleetVehicle &vehicle, string name);
void refuelVehicle(FleetVehicle &vehicle, float fuelAmount);

#endif
