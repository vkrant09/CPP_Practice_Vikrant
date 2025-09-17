// Question 1: Smart Diagnostics – Fault Simulation Engine
// Introduction
// In modern automotive systems, fault simulation is critical for validating
// embedded diagnostics. This challenge tasks you with building a modular fault
// simulation engine using C++ that models sensors, actuators, and fault
// injection logic—all managed via pointers and references.

// Scenario
// You’re part of a diagnostics team designing a simulation engine for an STM32-
// based automotive ECU. The system must simulate sensor faults, actuator
// delays, and log anomalies. Faults are injected dynamically, thresholds are
// updated via reference, and all memory is managed manually.

// Class Specifications
// Sensor (Abstract Base Class)
// • Attributes:
// int id, float value, float threshold, std::string status
// • Methods:
// virtual void simulateFault() = 0
// bool isFaulty() → returns true if value > threshold
// TemperatureSensor, PressureSensor (Derived)
// • Implement simulateFault() to inject realistic fault values
// Actuator
// • Attributes:
// int id, std::string state, int responseTime
// • Method:
// void triggerAction()
// FaultInjector
// • Attributes:
// std::vector<Sensor*> sensors, std::vector<Actuator*> actuators

// • Methods:
// void injectSensorFault(Sensor* s)
// void injectActuatorDelay(Actuator& a)
// void injectAllFaults()
// void reportStatus()
// SimulationEngine
// • Accepts ConfigManager& and FaultLogger*
// • Dynamically allocates sensors and actuators
// • Runs fault cycles and logs results
// ConfigManager
// • Method:
// void updateThreshold(Sensor& s, float newThreshold)
// FaultLogger
// • Method:
// void log(Sensor& s) → logs fault to file

// Global Functions
// void logFault(Sensor* s); // Logs fault via pointer
// void analyzeSystem(FaultInjector* fi); // System-wide fault analysis

// Sample Data
// TemperatureSensor* t1 = new TemperatureSensor(101, 95.0, 90.0);
// PressureSensor* p1 = new PressureSensor(102, 45.0, 50.0);
// Actuator* a1 = new Actuator(201, "Idle", 120);

// Tasks
// • Implement all classes with proper memory management
// • Use pointers for dynamic allocation and traversal
// • Use references for configuration and logging

// • Simulate a test run with 3 sensors and 2 actuators
// • Log faults and generate a system report

// Concepts Reinforced
// • Polymorphism, inheritance
// • Pointer-based object management
// • Reference-based updates and logging
// • Global function integration
// • Manual memory cleanup

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Sensor {
protected:
    int id;
    float value;
    float threshold;
    string status;
public:
    Sensor(int i, float v, float t) : id(i), value(v), threshold(t), status("OK") {}
    virtual ~Sensor() {}
    virtual void simulateFault() = 0;
    bool isFaulty() { return value > threshold; }
    int getId() { return id; }
    float getValue() { return value; }
    float getThreshold() { return threshold; }
    string getStatus() { return status; }
    void setThreshold(float t) { threshold = t; }
    void setStatus(string s) { status = s; }
};

class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(int i, float v, float t) : Sensor(i, v, t) {}
    void simulateFault() override {
        value += 15.0;
        status = "Temp Fault";
    }
};

class PressureSensor : public Sensor {
public:
    PressureSensor(int i, float v, float t) : Sensor(i, v, t) {}
    void simulateFault() override {
        value += 10.0;
        status = "Pressure Fault";
    }
};

class Actuator {
    int id;
    string state;
    int responseTime;
public:
    Actuator(int i, string s, int r) : id(i), state(s), responseTime(r) {}
    void triggerAction() {
        state = "Active";
        responseTime += 20;
    }
    int getId() { return id; }
    string getState() { return state; }
    int getResponseTime() { return responseTime; }
    void setState(string s) { state = s; }
};

class FaultInjector {
    vector<Sensor*> sensors;
    vector<Actuator*> actuators;
public:
    void addSensor(Sensor* s) { sensors.push_back(s); }
    void addActuator(Actuator* a) { actuators.push_back(a); }
    void injectSensorFault(Sensor* s) { s->simulateFault(); }
    void injectActuatorDelay(Actuator& a) { a.triggerAction(); }
    void injectAllFaults() {
        for (auto s : sensors) s->simulateFault();
        for (auto a : actuators) a->triggerAction();
    }
    void reportStatus() {
        cout << "Sensors:\n";
        for (auto s : sensors) {
            cout << "ID: " << s->getId() << " Value: " << s->getValue()
                 << " Threshold: " << s->getThreshold() << " Status: " << s->getStatus() << "\n";
        }
        cout << "Actuators:\n";
        for (auto a : actuators) {
            cout << "ID: " << a->getId() << " State: " << a->getState()
                 << " ResponseTime: " << a->getResponseTime() << "\n";
        }
    }
    vector<Sensor*>& getSensors() { return sensors; }
};

class ConfigManager {
public:
    void updateThreshold(Sensor& s, float newThreshold) {
        s.setThreshold(newThreshold);
    }
};

class FaultLogger {
    ofstream file;
public:
    FaultLogger(const string& filename) { file.open(filename); }
    ~FaultLogger() { if (file.is_open()) file.close(); }
    void log(Sensor& s) {
        if (file.is_open()) {
            file << "Sensor ID: " << s.getId() << " Fault Status: " << s.getStatus() << "\n";
        }
    }
};

void logFault(Sensor* s) {
    cout << "Global Log -> Sensor ID: " << s->getId() << " Status: " << s->getStatus() << "\n";
}

void analyzeSystem(FaultInjector* fi) {
    cout << "System Analysis:\n";
    for (auto s : fi->getSensors()) {
        cout << "Sensor " << s->getId() << " value: " << s->getValue()
             << " status: " << s->getStatus() << "\n";
    }
}

class SimulationEngine {
    ConfigManager& config;
    FaultLogger* logger;
    FaultInjector injector;
public:
    SimulationEngine(ConfigManager& c, FaultLogger* l) : config(c), logger(l) {}
    void setup() {
        Sensor* t1 = new TemperatureSensor(101, 95.0, 90.0);
        Sensor* p1 = new PressureSensor(102, 45.0, 50.0);
        Sensor* t2 = new TemperatureSensor(103, 85.0, 80.0);
        Actuator* a1 = new Actuator(201, "Idle", 120);
        Actuator* a2 = new Actuator(202, "Idle", 100);
        injector.addSensor(t1);
        injector.addSensor(p1);
        injector.addSensor(t2);
        injector.addActuator(a1);
        injector.addActuator(a2);
    }
    void run() {
        injector.injectAllFaults();
        for (auto s : injector.getSensors()) {
            if (s->isFaulty()) {
                logger->log(*s);
                logFault(s);
            }
        }
        injector.reportStatus();
        analyzeSystem(&injector);
    }
};

int main() {
    ConfigManager config;
    FaultLogger logger("faults.txt");
    SimulationEngine engine(config, &logger);
    engine.setup();
    engine.run();
    return 0;
}
