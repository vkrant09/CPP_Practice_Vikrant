#include "FleetVehicle.h"

// Default constructor
FleetVehicle::FleetVehicle() {
    vehicleID = 0;
    fuelLevel = 50.0;
    distanceTravelled = 0.0;
    status = 'A';
    isAvailable = true;
    driverName = "Unassigned";
}

// Parameterized constructor
FleetVehicle::FleetVehicle(int id, float fuel, double distance, char stat, bool available, string driver) {
    vehicleID = id;
    fuelLevel = fuel;
    distanceTravelled = distance;
    status = stat;
    isAvailable = available;
    driverName = driver;
}

// Destructor
FleetVehicle::~FleetVehicle() {
    cout << "Destructor called for vehicle ID: " << vehicleID << endl;
}

// Getters
int FleetVehicle::getVehicleID() const { return vehicleID; }
float FleetVehicle::getFuelLevel() const { return fuelLevel; }
double FleetVehicle::getDistanceTravelled() const { return distanceTravelled; }
char FleetVehicle::getStatus() const { return status; }
bool FleetVehicle::getAvailability() const { return isAvailable; }
string FleetVehicle::getDriverName() const { return driverName; }

// Setters
void FleetVehicle::setVehicleID(int id) { vehicleID = id; }
void FleetVehicle::setFuelLevel(float fuel) { fuelLevel = fuel; }
void FleetVehicle::setDistanceTravelled(double distance) { distanceTravelled = distance; }
void FleetVehicle::setStatus(char stat) { status = stat; }
void FleetVehicle::setAvailability(bool available) { isAvailable = available; }
void FleetVehicle::setDriverName(string name) { driverName = name; }

// Function to update vehicle status
void FleetVehicle::updateStatus() {
    if (fuelLevel < 10.0 || !isAvailable)
        status = 'I';  // Mark as inactive
    else
        status = 'A';  // Mark as active
}

// Display function
void FleetVehicle::displayInfo() const {
    cout << "\n----------------------------------\n";
    cout << "Vehicle ID: " << vehicleID << endl;
    cout << "Fuel Level: " << fuelLevel << " L" << endl;
    cout << "Distance Travelled: " << distanceTravelled << " km" << endl;
    cout << "Status: " << (status == 'A' ? "Active" : "Inactive") << endl;
    cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
    cout << "Driver Name: " << driverName << endl;
    cout << "----------------------------------\n";
}

// Assign driver function
void assignDriver(FleetVehicle &vehicle, string name) {
    vehicle.setDriverName(name);
    cout << "Driver '" << vehicle.getDriverName() << "' assigned to vehicle ID: " << vehicle.getVehicleID() << endl;
}

// Refuel vehicle function
void refuelVehicle(FleetVehicle &vehicle, float fuelAmount) {
    if (fuelAmount <= 0)
        throw invalid_argument("Fuel amount must be positive.");

    float newFuel = vehicle.getFuelLevel() + fuelAmount;
    vehicle.setFuelLevel(newFuel);
    cout << "Vehicle ID " << vehicle.getVehicleID() << " refueled successfully. Current fuel: " << vehicle.getFuelLevel() << " L\n";
}
