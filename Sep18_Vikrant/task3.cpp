#include <iostream>
#include <string>
using namespace std;

enum SatelliteStatus { OPERATIONAL, MAINTENANCE, DECOMMISSIONED };

class SatelliteData {
private:
    int satellite_id;
    int num_antennas;
    float* signal_strength;
    float orbital_altitude;
    SatelliteStatus status;
    static int active_satellites;

public:
    SatelliteData(int id, int n, const float s[], float alt, SatelliteStatus st)
        : satellite_id(id), num_antennas(n), orbital_altitude(alt), status(st) {
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++) signal_strength[i] = s[i];
        active_satellites++;
    }

    // copy constructor
    SatelliteData(const SatelliteData& other) {
        satellite_id = other.satellite_id;
        num_antennas = other.num_antennas;
        orbital_altitude = other.orbital_altitude;
        status = other.status;
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++) signal_strength[i] = other.signal_strength[i];
        active_satellites++;
    }

    ~SatelliteData() {
        delete[] signal_strength;
        active_satellites--;
    }

    float getAverageSignalStrength() const {
        float sum = 0;
        for (int i = 0; i < num_antennas; i++) sum += signal_strength[i];
        return sum / num_antennas;
    }

    void boostSignal(float factor) {
        for (int i = 0; i < num_antennas; i++) signal_strength[i] *= factor;
    }

    void boostSignal(float factor, float threshold) {
        for (int i = 0; i < num_antennas; i++)
            if (signal_strength[i] < threshold) signal_strength[i] *= factor;
    }

    static int getActiveSatelliteCount() { return active_satellites; }

    void setStatus(SatelliteStatus s) { status = s; }

    // getters
    int getId() const { return satellite_id; }
    float getAltitude() const { return orbital_altitude; }
    int getNumAntennas() const { return num_antennas; }
    float getSignal(int i) const { return signal_strength[i]; }
    string getStatusString() const {
        switch (status) {
            case OPERATIONAL: return "Operational";
            case MAINTENANCE: return "Maintenance";
            case DECOMMISSIONED: return "Decommissioned";
        }
        return "Unknown";
    }
};

int SatelliteData::active_satellites = 0;

// global functions
void printSatelliteData(const SatelliteData& s) {
    cout << "Satellite " << s.getId() << " Alt: " << s.getAltitude() << " Signals: ";
    for (int i = 0; i < s.getNumAntennas(); i++) cout << s.getSignal(i) << " ";
    cout << " Status: " << s.getStatusString() << "\n";
}

bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2) {
    return s1.getAltitude() > s2.getAltitude();
}

void cloneSatellite(const SatelliteData& src, SatelliteData*& dest) {
    dest = new SatelliteData(src);
}

void updateStatusIfWeak(SatelliteData& s, float th) {
    if (s.getAverageSignalStrength() < th) s.setStatus(MAINTENANCE);
}

int main() {
    float a1[] = {78.5f, 80.2f, 79.0f};
    float a2[] = {75.0f, 76.5f};

    SatelliteData sat1(101, 3, a1, 550.0f, OPERATIONAL);
    SatelliteData sat2(102, 2, a2, 600.0f, MAINTENANCE);

    sat1.boostSignal(1.1f);
    sat2.boostSignal(1.2f, 76.0f);

    cout << (compareAltitude(sat1, sat2) ? "Sat1 higher\n" : "Sat2 higher\n");

    SatelliteData* sat3 = nullptr;
    cloneSatellite(sat1, sat3);

    printSatelliteData(sat1);
    printSatelliteData(sat2);
    printSatelliteData(*sat3);

    updateStatusIfWeak(sat2, 77.0f);
    printSatelliteData(sat2);

    cout << "Active satellites: " << SatelliteData::getActiveSatelliteCount() << "\n";

    delete sat3;
    cout << "Active satellites: " << SatelliteData::getActiveSatelliteCount() << "\n";
}
