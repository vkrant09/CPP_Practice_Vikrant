#include <iostream>
#include <string>
using namespace std;

class FleetVehicle {
private:
    int vehicleID;
    float fuelLevel;
    double distanceTravelled;
    char status;
    bool isAvailable;
    string driverName;

public:
    FleetVehicle() : vehicleID(0), fuelLevel(50.0), distanceTravelled(0.0),
        status('A'), isAvailable(true), driverName("Unassigned") {}

    FleetVehicle(int id, float fuel, double dist, char st, bool avail, string driver)
        : vehicleID(id), fuelLevel(fuel), distanceTravelled(dist),
          status(st), isAvailable(avail), driverName(driver) {}

    ~FleetVehicle() { cout << "Destructor called for vehicle ID: " << vehicleID << "\n"; }

    // Getters
    int getId() const { return vehicleID; }
    float getFuel() const { return fuelLevel; }
    char getStatus() const { return status; }
    string getDriver() const { return driverName; }

    // Setters
    void setDriver(const string &d) { driverName = d; }
    void setFuel(float f) { fuelLevel = f; }
    void setAvailable(bool avail) { isAvailable = avail; }

    void updateStatus() {
        status = (fuelLevel < 10.0 || !isAvailable) ? 'I' : 'A';
    }

    void displayInfo() const {
        cout << "ID: " << vehicleID << " | Fuel: " << fuelLevel
             << " | Distance: " << distanceTravelled << " | Status: " << status
             << " | Available: " << (isAvailable ? "Yes" : "No")
             << " | Driver: " << driverName << "\n";
    }
};

// Global functions
void assignDriver(FleetVehicle &v, string name) {
    v.setDriver(name);
    cout << "Driver assigned: " << v.getDriver() << "\n";
}

void refuelVehicle(FleetVehicle &v, float amount) {
    if (amount <= 0) throw runtime_error("Invalid fuel amount!");
    v.setFuel(v.getFuel() + amount);
    cout << "Vehicle " << v.getId() << " refueled. New Fuel: " << v.getFuel() << "\n";
}

int main() {
    FleetVehicle vehicles[3] = {
        FleetVehicle(101, 45.5, 120.0, 'A', true, "Raj"),
        FleetVehicle(102, 8.0, 300.0, 'A', true, "Priya"),
        FleetVehicle()
    };

    int choice;
    do {
        cout << "\n1. Add Vehicle\n2. Assign Driver\n3. Refuel Vehicle\n"
             << "4. Update Status\n5. Display Info\n6. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id; float f; double d; char st; bool avail; string driver;
                cout << "Enter ID Fuel Distance Status(A/I) Available(1/0) Driver: ";
                cin >> id >> f >> d >> st >> avail >> driver;
                vehicles[0] = FleetVehicle(id, f, d, st, avail, driver);
                break;
            }
            case 2: {
                int id; string name;
                cout << "Enter Vehicle ID & Driver: "; cin >> id >> name;
                for (auto &v : vehicles) if (v.getId() == id) assignDriver(v, name);
                break;
            }
            case 3: {
                int id; float amt;
                cout << "Enter Vehicle ID & Fuel Amount: "; cin >> id >> amt;
                for (auto &v : vehicles) if (v.getId() == id) {
                    try { refuelVehicle(v, amt); }
                    catch (exception &e) { cout << e.what() << "\n"; }
                }
                break;
            }
            case 4: {
                int id; cout << "Enter Vehicle ID: "; cin >> id;
                for (auto &v : vehicles) if (v.getId() == id) v.updateStatus();
                break;
            }
            case 5: for (auto &v : vehicles) v.displayInfo(); break;
        }
    } while (choice != 6);

    return 0;
}
