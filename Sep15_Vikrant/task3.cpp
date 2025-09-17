#include <iostream>
#include <string>
using namespace std;

enum ComponentType { ENGINE, AVIONICS, LANDING_GEAR, FUEL_SYSTEM };
enum ComponentStatus { OPERATIONAL, MAINTENANCE_REQUIRED, FAILED };

class AerospaceComponent {
private:
    int componentIdentifier;
    double componentEfficiency;
    string componentManufacturer;
    ComponentType componentType;
    ComponentStatus componentStatus;

public:
    AerospaceComponent() 
        : componentIdentifier(0), componentEfficiency(100.0), 
          componentManufacturer("Unknown"), componentType(ENGINE), 
          componentStatus(OPERATIONAL) {}

    AerospaceComponent(int id, double eff, const string &man, ComponentType type, ComponentStatus status) 
        : componentIdentifier(id), componentEfficiency(eff), 
          componentManufacturer(man), componentType(type), 
          componentStatus(status) {}

    ~AerospaceComponent() { cout << "Component " << componentIdentifier << " destroyed.\n"; }

    void UpdateStatus() {
        if (componentEfficiency < 50.0) componentStatus = FAILED;
        else if (componentEfficiency < 80.0) componentStatus = MAINTENANCE_REQUIRED;
        else componentStatus = OPERATIONAL;
    }

    void SimulateUsage(int hours) {
        for (int i = 0; i < hours; i++) {
            componentEfficiency -= 0.5;
            if (componentEfficiency < 0) { componentEfficiency = 0; break; }
        }
        UpdateStatus();
    }

    void PerformMaintenanceCheck() {
        switch (componentStatus) {
            case FAILED: cout << "Component " << componentIdentifier << " FAILED. Replace immediately.\n"; break;
            case MAINTENANCE_REQUIRED: cout << "Component " << componentIdentifier << " needs maintenance.\n"; break;
            default: cout << "Component " << componentIdentifier << " is operational.\n"; break;
        }
    }

    void BoostEfficiency() {
        while (componentEfficiency < 100.0) componentEfficiency += 1.0;
        UpdateStatus();
    }

    void DisplayDetails() const {
        cout << "ID: " << componentIdentifier 
             << " | Eff: " << componentEfficiency 
             << " | Mfg: " << componentManufacturer
             << " | Type: " << componentType 
             << " | Status: " << componentStatus << "\n";
    }

    // Getters & Setters
    int getId() const { return componentIdentifier; }
    double getEfficiency() const { return componentEfficiency; }
    ComponentType getType() const { return componentType; }
    ComponentStatus getStatus() const { return componentStatus; }
    void setManufacturer(const string &m) { componentManufacturer = m; }
};

void AssignManufacturer(AerospaceComponent &c, const string &m) { c.setManufacturer(m); }
bool IsEfficient(const AerospaceComponent &c) { return c.getEfficiency() > 85.0; }
bool IsSameType(const AerospaceComponent &a, const AerospaceComponent &b) { return a.getType() == b.getType(); }
bool IsSameStatus(const AerospaceComponent &a, const AerospaceComponent &b) { return a.getStatus() == b.getStatus(); }

void PrintFormattedComponentList(const AerospaceComponent comps[], int n) {
    cout << "ID | Eff | Manufacturer | Type | Status\n";
    for (int i = 0; i < n; i++) comps[i].DisplayDetails();
}

int SearchComponentByIdentifier(const AerospaceComponent comps[], int n, int id) {
    for (int i = 0; i < n; i++) if (comps[i].getId() == id) return i;
    return -1;
}

int main() {
    AerospaceComponent components[3] = {
        AerospaceComponent(101, 92.5, "GE Aviation", ENGINE, OPERATIONAL),
        AerospaceComponent(102, 45.0, "Honeywell", AVIONICS, FAILED),
        AerospaceComponent()
    };

    int choice;
    do {
        cout << "\n1. Assign Manufacturer\n2. Simulate Usage\n3. Boost Efficiency\n4. Check Maintenance\n"
             << "5. Compare Components\n6. Search by ID\n7. Display All\n8. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int id; string m;
            cout << "Enter ID & Manufacturer: "; cin >> id >> m;
            int idx = SearchComponentByIdentifier(components, 3, id);
            if (idx != -1) AssignManufacturer(components[idx], m);
        }
        else if (choice == 2) {
            int id,h; cout << "Enter ID & Hours: "; cin >> id >> h;
            int idx = SearchComponentByIdentifier(components, 3, id);
            if (idx != -1) components[idx].SimulateUsage(h);
        }
        else if (choice == 3) {
            int id; cout << "Enter ID: "; cin >> id;
            int idx = SearchComponentByIdentifier(components, 3, id);
            if (idx != -1) components[idx].BoostEfficiency();
        }
        else if (choice == 4) {
            int id; cout << "Enter ID: "; cin >> id;
            int idx = SearchComponentByIdentifier(components, 3, id);
            if (idx != -1) components[idx].PerformMaintenanceCheck();
        }
        else if (choice == 5) {
            int id1,id2; cout << "Enter two IDs: "; cin >> id1 >> id2;
            int a = SearchComponentByIdentifier(components, 3, id1);
            int b = SearchComponentByIdentifier(components, 3, id2);
            if (a!=-1 && b!=-1) {
                cout << "Same Type? " << IsSameType(components[a], components[b]) << "\n";
                cout << "Same Status? " << IsSameStatus(components[a], components[b]) << "\n";
            }
        }
        else if (choice == 6) {
            int id; cout << "Enter ID: "; cin >> id;
            int idx = SearchComponentByIdentifier(components, 3, id);
            if (idx!=-1) components[idx].DisplayDetails();
            else cout << "Not Found\n";
        }
        else if (choice == 7) PrintFormattedComponentList(components, 3);

    } while (choice != 8);

    return 0;
}
