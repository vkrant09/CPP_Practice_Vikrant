#include <iostream>
using namespace std;

class Pedestrian {
private:
    unsigned int pedestrian_id;
    float distance_from_vehicle;

public:
    Pedestrian(unsigned int id, float dist) : pedestrian_id(id), distance_from_vehicle(dist) {}

    void updateDistance(float newDistance) { distance_from_vehicle = newDistance; }
    float getDistance() const { return distance_from_vehicle; }
    unsigned int getId() const { return pedestrian_id; }
};

// global functions
void printPedestrianInfo(const Pedestrian& ped) {
    cout << "Pedestrian " << ped.getId() << " | Distance: " << ped.getDistance() << " m\n";
}

void findClosestPedestrian(Pedestrian* arr, unsigned int size, const Pedestrian*& closest) {
    if (size == 0) { closest = nullptr; return; }
    closest = &arr[0];
    for (unsigned int i = 1; i < size; i++)
        if (arr[i].getDistance() < closest->getDistance()) closest = &arr[i];
}

void printClosestPedestrian(const Pedestrian* closest) {
    if (closest) {
        cout << "Closest Pedestrian -> ID: " << closest->getId()
             << ", Distance: " << closest->getDistance() << " m\n";
    }
}

int main() {
    Pedestrian* arr = new Pedestrian[3]{
        {101, 12.4f}, {102, 8.7f}, {103, 15.1f}
    };

    for (int i = 0; i < 3; i++) printPedestrianInfo(arr[i]);

    const Pedestrian* closest = nullptr;
    findClosestPedestrian(arr, 3, closest);
    printClosestPedestrian(closest);

    delete[] arr;
    return 0;
}
