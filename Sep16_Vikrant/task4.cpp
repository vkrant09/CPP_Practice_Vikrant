#include <iostream>
using namespace std;

class RadarSignal {
private:
    int num_channels;
    float* strength;

public:
    // constructor
    RadarSignal(int n, float s[]) : num_channels(n) {
        strength = new float[n];
        for (int i = 0; i < n; i++) strength[i] = s[i];
    }

    // deep copy constructor
    RadarSignal(const RadarSignal& other) {
        num_channels = other.num_channels;
        strength = new float[num_channels];
        for (int i = 0; i < num_channels; i++) {
            strength[i] = other.strength[i];
        }
    }

    // destructor
    ~RadarSignal() { delete[] strength; }

    float averageSignal() const {
        float sum = 0;
        for (int i = 0; i < num_channels; i++) sum += strength[i];
        return sum / num_channels;
    }

   void boostSignalByValue(RadarSignal obj) {
        for (int i = 0; i < obj.num_channels; i++) obj.strength[i] += 5.0;
    }

    void boostSignalByReference(RadarSignal& obj) {
        for (int i = 0; i < obj.num_channels; i++) obj.strength[i] += 5.0;
    }

    int getChannels() const { return num_channels; }
    float getSignal(int i) const { return strength[i]; }
};

// global
void printRadarSignal(const RadarSignal& r) {
    for (int i = 0; i < r.getChannels(); i++)
        cout << r.getSignal(i) << " ";
    cout << "\n";
}

RadarSignal* createRadarSignalHeap(int n, float* s) {
    return new RadarSignal(n, s);
}

int main() {
    float s[4] = {55.5f, 48.2f, 60.1f, 52.6f};
    RadarSignal* radar = createRadarSignalHeap(4, s);

    cout << "Original signals: "; printRadarSignal(*radar);

    radar->boostSignalByValue(*radar); // no effect on original
    cout << "After by value: "; printRadarSignal(*radar);

    radar->boostSignalByReference(*radar); // changes original
    cout << "After by reference: "; printRadarSignal(*radar);

    cout << "Average: " << radar->averageSignal() << "\n";

    delete radar;
    return 0;
}
