#include <iostream>
using namespace std;

class VehicleStatus {
private:
    int num_wheels, num_temps;
    float* wheel_speed;
    float* engine_temp;

public:
    // constructor
    VehicleStatus(int nw, float* ws, int nt, float* et)
        : num_wheels(nw), num_temps(nt) {
        wheel_speed = new float[nw];
        engine_temp = new float[nt];
        for (int i = 0; i < nw; i++) wheel_speed[i] = ws[i];
        for (int i = 0; i < nt; i++) engine_temp[i] = et[i];
    }

    // copy constructor for safety
    VehicleStatus(const VehicleStatus& other) {
        num_wheels = other.num_wheels;
        num_temps = other.num_temps;
        wheel_speed = new float[num_wheels];
        engine_temp = new float[num_temps];
        for (int i = 0; i < num_wheels; i++) wheel_speed[i] = other.wheel_speed[i];
        for (int i = 0; i < num_temps; i++) engine_temp[i] = other.engine_temp[i];
    }

    ~VehicleStatus() { delete[] wheel_speed; delete[] engine_temp; }

    float averageWheelSpeed() const {
        float sum = 0;
        for (int i = 0; i < num_wheels; i++) sum += wheel_speed[i];
        return sum / num_wheels;
    }

    float maxEngineTemp() const {
        float maxT = engine_temp[0];
        for (int i = 1; i < num_temps; i++) if (engine_temp[i] > maxT) maxT = engine_temp[i];
        return maxT;
    }

    bool isWheelSpeedHigher(const VehicleStatus& other) const {
        float maxThis = wheel_speed[0], maxOther = other.wheel_speed[0];
        for (int i = 1; i < num_wheels; i++) if (wheel_speed[i] > maxThis) maxThis = wheel_speed[i];
        for (int j = 1; j < other.num_wheels; j++) if (other.wheel_speed[j] > maxOther) maxOther = other.wheel_speed[j];
        return this->averageWheelSpeed() > other.averageWheelSpeed();
    }

    friend void printVehicleStatus(const VehicleStatus& vs);
};

void printVehicleStatus(const VehicleStatus& vs) {
    cout << "Wheel Speeds: ";
    for (int i = 0; i < vs.num_wheels; i++) cout << vs.wheel_speed[i] << " ";
    cout << "| Temps: ";
    for (int i = 0; i < vs.num_temps; i++) cout << vs.engine_temp[i] << " ";
    cout << "\n";
}

bool compareWheelSpeedGlobal(const VehicleStatus& v1, const VehicleStatus& v2) {
    return v1.isWheelSpeedHigher(v2);
}

int main() {
    float ws1[4] = {55.5f, 56.6f, 57.2f, 55.9f};
    float et1[2] = {90.5f, 88.9f};
    float ws2[4] = {50.0f, 51.2f, 49.8f, 50.4f};
    float et2[2] = {92.0f, 89.5f};

    VehicleStatus v1(4, ws1, 2, et1);
    VehicleStatus v2(4, ws2, 2, et2);

    printVehicleStatus(v1);
    printVehicleStatus(v2);

    cout << "Member compare: " << (v1.isWheelSpeedHigher(v2) ? "V1 higher" : "V2 higher") << "\n";
    cout << "Global compare: " << (compareWheelSpeedGlobal(v1, v2) ? "V1 higher" : "V2 higher") << "\n";
    return 0;
}
