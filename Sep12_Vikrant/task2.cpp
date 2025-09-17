// Question 2: Sensor Grid – Dynamic Reference Binding
// Introduction
// In embedded systems, dynamic binding to critical components is essential.
// This challenge simulates a sensor grid where a controller binds to the highestpriority sensor using references, while managing all sensors via pointers.
// Scenario
// You’re developing a sensor grid for an autonomous vehicle. The controller
// must always reference the most critical sensor (highest priority). Sensor
// health is monitored via reference, and global functions help rebind and
// visualize the grid.
// Class Specifications
// Sensor
// • Attributes:
// int id, float value, int priority, std::string status
// • Method:
// void updateValue(float v)
// Controller
// • Attributes:
// Sensor* sensorList[10]
// Sensor& criticalSensor
// • Methods:
// void bindCriticalSensor()
// void updateCriticalSensor() → uses global function
// void printStatus()
// SensorDiagnostics
// • Method:
// std::string checkHealth(Sensor& s)
 
// Global Functions
// void rebindCriticalSensor(Sensor*& ref, Sensor* list[], int size);
// void printSensorMap(Sensor* list[], int size);
// Sample Data
// Sensor* s1 = new Sensor(1, 75.0, 3);
// Sensor* s2 = new Sensor(2, 60.0, 5);
// Sensor* s3 = new Sensor(3, 90.0, 2);
// Sensor* sensorList[3] = {s1, s2, s3};
// Tasks
// • Dynamically allocate 10 sensors with varying priorities
// • Use reference to bind to highest priority sensor
// • Modify sensor via reference and observe changes
// • Use global functions to rebind and print sensor map
// • Clean up memory safely
// Concepts Reinforced
// • Reference-to-pointer rebinding
// • Pointer arrays and dynamic access
// • Global function manipulation of references
// • Reference-based health checks
// • Manual memory management

#include <iostream>
#include <string>
using namespace std;

class Sensor {
    int id;
    float value;
    int priority;
    string status;
public:
    Sensor(int i, float v, int p) : id(i), value(v), priority(p), status("OK") {}
    void updateValue(float v) { value = v; }
    int getId() { return id; }
    float getValue() { return value; }
    int getPriority() { return priority; }
    string getStatus() { return status; }
    void setStatus(string s) { status = s; }
};

class SensorDiagnostics {
public:
    string checkHealth(Sensor& s) {
        return (s.getValue() > 100) ? "Unhealthy" : "Healthy";
    }
};

void rebindCriticalSensor(Sensor*& ref, Sensor* list[], int size) {
    Sensor* highest = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i]->getPriority() > highest->getPriority()) {
            highest = list[i];
        }
    }
    ref = highest;
}

void printSensorMap(Sensor* list[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Sensor ID: " << list[i]->getId()
             << " Value: " << list[i]->getValue()
             << " Priority: " << list[i]->getPriority()
             << " Status: " << list[i]->getStatus() << "\n";
    }
}

class Controller {
    Sensor* sensorList[10];
    Sensor* criticalPtr;
    int size;
public:
    Controller() : criticalPtr(nullptr), size(0) {}
    void addSensor(Sensor* s) {
        if (size < 10) sensorList[size++] = s;
    }
    void bindCriticalSensor() {
        rebindCriticalSensor(criticalPtr, sensorList, size);
    }
    void updateCriticalSensor() {
        rebindCriticalSensor(criticalPtr, sensorList, size);
    }
    void printStatus() {
        if (criticalPtr) {
            cout << "Critical Sensor -> ID: " << criticalPtr->getId()
                 << " Value: " << criticalPtr->getValue()
                 << " Priority: " << criticalPtr->getPriority() << "\n";
        }
    }
    Sensor** getSensorList() { return sensorList; }
    int getSize() { return size; }
    Sensor* getCriticalPtr() { return criticalPtr; }
};

int main() {
    Controller ctrl;
    for (int i = 0; i < 10; i++) {
        Sensor* s = new Sensor(i + 1, 50 + i * 5, (i % 5) + 1);
        ctrl.addSensor(s);
    }

    ctrl.bindCriticalSensor();
    ctrl.printStatus();

    SensorDiagnostics diag;
    cout << "Health of critical: " << diag.checkHealth(*ctrl.getCriticalPtr()) << "\n";

    ctrl.getSensorList()[3]->updateValue(120);
    ctrl.updateCriticalSensor();
    ctrl.printStatus();

    printSensorMap(ctrl.getSensorList(), ctrl.getSize());

    for (int i = 0; i < ctrl.getSize(); i++) {
        delete ctrl.getSensorList()[i];
    }
    return 0;
}
