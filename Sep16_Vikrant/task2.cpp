#include <iostream>
using namespace std;

class ObjectDistance {
private:
    float radar_distance;
    float camera_distance;

public:
    ObjectDistance(float r, float c) : radar_distance(r), camera_distance(c) {}

    void adjustDistancesByValue(ObjectDistance obj) {
        obj.radar_distance += 5.0; 
        obj.camera_distance += 5.0;
        // here changes are only local (copy)
    }

    void adjustDistancesByReference(ObjectDistance& obj) {
        obj.radar_distance += 5.0;
        obj.camera_distance += 5.0;
    }

    float getRadar() const { return radar_distance; }
    float getCamera() const { return camera_distance; }
};

// global functions
void printObjectDistance(const ObjectDistance& obj) {
    cout << "Radar: " << obj.getRadar() << " | Camera: " << obj.getCamera() << "\n";
}

ObjectDistance* createObjectDistanceOnHeap(float radar, float camera) {
    return new ObjectDistance(radar, camera);
}

int main() {
    ObjectDistance* obj = createObjectDistanceOnHeap(35.5f, 34.8f);

    cout << "Before adjustment:\n";
    printObjectDistance(*obj);

    obj->adjustDistancesByValue(*obj); // won't change
    cout << "After by value:\n";
    printObjectDistance(*obj);

    obj->adjustDistancesByReference(*obj); // will change
    cout << "After by reference:\n";
    printObjectDistance(*obj);

    delete obj; // cleanup
    return 0;
}
