#include <iostream>
using namespace std;

class DetectedObject {
private:
    unsigned int object_id;
    float rel_speed, distance;

public:
    DetectedObject(unsigned int id, float spd, float dist)
        : object_id(id), rel_speed(spd), distance(dist) {}

    void display() const {
        cout << "Object " << object_id << " | RelSpeed: " << rel_speed
             << " | Distance: " << distance << "\n";
    }

    bool isHigherRisk(const DetectedObject& other) const {
        return (this->distance < other.distance) && (this->rel_speed > other.rel_speed);
    }

    void updateValuesByValue(DetectedObject obj) {
        obj.rel_speed += 2; obj.distance -= 5;
        cout << "[Inside By Value] RelSpeed: " << obj.rel_speed << " | Dist: " << obj.distance << "\n";
    }

    void updateValuesByReference(DetectedObject& obj) {
        obj.rel_speed += 2; obj.distance -= 5;
    }

    unsigned int getId() const { return object_id; }
    float getRelSpeed() const { return rel_speed; }
    float getDistance() const { return distance; }
};

void printDetectedObject(const DetectedObject& obj) { obj.display(); }

void findHighestRiskObject(DetectedObject* arr, unsigned int size, const DetectedObject*& riskObj) {
    riskObj = &arr[0];
    for (unsigned int i = 1; i < size; i++)
        if (arr[i].isHigherRisk(*riskObj)) riskObj = &arr[i];
}

void printHighestRiskObject(const DetectedObject* obj) {
    if (obj) cout << "Highest Risk Object: " << obj->getId() << "\n";
}

int main() {
    DetectedObject* arr = new DetectedObject[3]{
        {701, 15, 55}, {702, 20, 35}, {703, 10, 30}
    };

    for (int i = 0; i < 3; i++) printDetectedObject(arr[i]);

    arr[0].updateValuesByValue(arr[0]); // won’t affect original
    arr[1].updateValuesByReference(arr[1]); // affects original

    const DetectedObject* risk = nullptr;
    findHighestRiskObject(arr, 3, risk);
    printHighestRiskObject(risk);

    delete[] arr;
    return 0;
}
