
#include "FleetVehicle.h"
#include <iostream>
using namespace std;

int main() {
    FleetVehicle vehicles[3] = {
        FleetVehicle(101, 45.5, 120.0, 'A', true, "Raj"),
        FleetVehicle(102, 8.0, 300.0, 'A', true, "Priya"),
        FleetVehicle() // Default constructor
    };

    int choice;
    do {
        cout << "\n==================== FLEET MANAGEMENT MENU ====================\n";
        cout << "1. Add Vehicle Details\n";
        cout << "2. Assign Driver\n";
        cout << "3. Refuel Vehicle\n";
        cout << "4. Update Vehicle Status\n";
        cout << "5. Display Vehicle Info\n";
        cout << "6. Exit\n";
        cout << "===============================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int index;
            cout << "Enter vehicle index (0-2): ";
            cin >> index;
            if (index < 0 || index >= 3) {
                cout << "Invalid index!\n";
                break;
            }
            int id;
            float fuel;
            double dist;
            char stat;
            bool available;
            string driver;

            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter Fuel Level: ";
            cin >> fuel;
            cout << "Enter Distance Travelled: ";
            cin >> dist;
            cout << "Enter Status (A/I): ";
            cin >> stat;
            cout << "Is Vehicle Available (1 for Yes / 0 for No): ";
            cin >> available;
            cout << "Enter Driver Name: ";
            cin.ignore();
            getline(cin, driver);

            vehicles[index] = FleetVehicle(id, fuel, dist, stat, available, driver);
            cout << "Vehicle details added successfully!\n";
            break;
        }

        case 2: {
            int id;
            cout << "Enter vehicle index (0-2): ";
            cin >> id;
            if (id < 0 || id >= 3) {
                cout << "Invalid index!\n";
                break;
            }
            string name;
            cout << "Enter driver name: ";
            cin.ignore();
            getline(cin, name);
            assignDriver(vehicles[id], name);
            break;
        }

        case 3: {
            int id;
            float fuelAmt;
            cout << "Enter vehicle index (0-2): ";
            cin >> id;
            if (id < 0 || id >= 3) {
                cout << "Invalid index!\n";
                break;
            }
            cout << "Enter fuel amount to add: ";
            cin >> fuelAmt;

            try {
                refuelVehicle(vehicles[id], fuelAmt);
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 4: {
            int id;
            cout << "Enter vehicle index (0-2): ";
            cin >> id;
            if (id < 0 || id >= 3) {
                cout << "Invalid index!\n";
                break;
            }
            vehicles[id].updateStatus();
            cout << "Status updated successfully!\n";
            break;
        }

        case 5: {
            for (int i = 0; i < 3; i++)
                vehicles[i].displayInfo();
            break;
        }

        case 6:
            cout << "Exiting Fleet Management System...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
