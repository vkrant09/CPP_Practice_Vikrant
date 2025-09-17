#include <iostream>
using namespace std;

enum SensorType { LIDAR, RADAR, CAMERA };

class SensorArray {
private:
    int sensor_id, num_readings;
    double* temperature_readings;
    SensorType type;
    static double global_max_temperature;

public:
    SensorArray(int id, SensorType t, double readings[], int n)
        : sensor_id(id), type(t), num_readings(n) {
        temperature_readings = new double[n];
        for (int i = 0; i < n; i++) {
            temperature_readings[i] = readings[i];
            if (temperature_readings[i] > global_max_temperature)
                global_max_temperature = temperature_readings[i];
        }
    }

    ~SensorArray() { delete[] temperature_readings; }

    double getMaxTemperature() const {
        double maxT = temperature_readings[0];
        for (int i = 1; i < num_readings; i++)
            if (temperature_readings[i] > maxT) maxT = temperature_readings[i];
        return maxT;
    }

    void printSensorInfo() const {
        const char* names[] = {"LIDAR", "RADAR", "CAMERA"};
        cout << "Sensor " << sensor_id << " (" << names[type] 
             << ") | Max Temp: " << getMaxTemperature() << "\n";
    }

    static double getGlobalMaxTemperature() { return global_max_temperature; }
};

double SensorArray::global_max_temperature = 0.0;

void printAllSensors(SensorArray* arr, int size) {
    for (int i = 0; i < size; i++) arr[i].printSensorInfo();
}

int main() {
    double s1[] = {35.5, 36.1, 34.9};
    double s2[] = {39.0, 38.7, 39.3};
    double s3[] = {30.2, 31.0, 30.5};

    SensorArray* arr = new SensorArray[3]{
        {801, LIDAR, s1, 3}, {802, RADAR, s2, 3}, {803, CAMERA, s3, 3}
    };

    printAllSensors(arr, 3);
    cout << "Global Max Temperature: " << SensorArray::getGlobalMaxTemperature() << "\n";

    delete[] arr;
    return 0;
}
