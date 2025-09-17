#include <iostream>
using namespace std;

class TrackedVehicle {
private:
    unsigned int vehicle_id;
    float speed, distance;
    static float min_recorded_distance;
    static int vehicle_count;

public:
    TrackedVehicle(unsigned int id, float spd, float dist)
        : vehicle_id(id), speed(spd), distance(dist) {
        if (vehicle_count == 0 || dist < min_recorded_distance)
            min_recorded_distance = dist;
        vehicle_count++;
    }

    void display() const {
        cout << "Vehicle " << vehicle_id << " | Speed: " << speed
             << " km/h | Distance: " << distance << " m\n";
    }

    float getDistance() const { return distance; }
    unsigned int getId() const { return vehicle_id; }

    const TrackedVehicle* compareDistance(const TrackedVehicle& other) const {
        return (this->distance <= other.distance) ? this : &other;
    }

    static float getMinRecordedDistance() { return min_recorded_distance; }
    static int getVehicleCount() { return vehicle_count; }
};

float TrackedVehicle::min_recorded_distance = 0;
int TrackedVehicle::vehicle_count = 0;

void findLeadVehicle(TrackedVehicle* arr, unsigned int size, const TrackedVehicle*& lead) {
    lead = &arr[0];
    for (unsigned int i = 1; i < size; i++)
        if (arr[i].getDistance() < lead->getDistance()) lead = &arr[i];
}

void printTrackedVehicle(const TrackedVehicle& v) { v.display(); }
void printLeadVehicle(const TrackedVehicle* lead) {
    if (lead) cout << "Lead Vehicle: " << lead->getId() << " at " << lead->getDistance() << " m\n";
}

int main() {
    TrackedVehicle* arr = new TrackedVehicle[4]{
        {501, 80, 60}, {502, 78, 45}, {503, 85, 100}, {504, 76, 40}
    };

    for (int i = 0; i < 4; i++) printTrackedVehicle(arr[i]);

    const TrackedVehicle* lead = nullptr;
    findLeadVehicle(arr, 4, lead);
    printLeadVehicle(lead);

    cout << "Min Recorded Distance: " << TrackedVehicle::getMinRecordedDistance() << " m\n";
    cout << "Total Vehicles Tracked: " << TrackedVehicle::getVehicleCount() << "\n";

    delete[] arr;
    return 0;
}
