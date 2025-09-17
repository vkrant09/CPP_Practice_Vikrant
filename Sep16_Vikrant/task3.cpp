#include <iostream>
using namespace std;

class CameraConfig {
private:
    int num_modes;
    int* width;
    int* height;

public:
    // constructor
    CameraConfig(int n, int w[], int h[]) : num_modes(n) {
        width = new int[n];
        height = new int[n];
        for (int i = 0; i < n; i++) { width[i] = w[i]; height[i] = h[i]; }
    }

    // copy constructor
    CameraConfig(const CameraConfig& other) : num_modes(other.num_modes) {
        width = new int[num_modes];
        height = new int[num_modes];
        for (int i = 0; i < num_modes; i++) {
            width[i] = other.width[i];
            height[i] = other.height[i];
        }
    }

    // destructor
    ~CameraConfig() { delete[] width; delete[] height; }

    void printConfig() const {
        for (int i = 0; i < num_modes; i++)
            cout << "Mode " << i << ": " << width[i] << "x" << height[i] << "\n";
    }

    bool isHigherResolution(int m1, int m2) const {
        int res1 = width[m1] * height[m1];
        int res2 = width[m2] * height[m2];
        return this->width[m1] * this->height[m1] > res2;
    }
};

// global
void printCameraConfig(const CameraConfig& cfg) { cfg.printConfig(); }

bool globalCompareResolution(const CameraConfig& cfg, int m1, int m2) {
    return cfg.isHigherResolution(m1, m2);
}

int main() {
    int w[3] = {1920, 1280, 3840};
    int h[3] = {1080, 2160, 2160};

    CameraConfig cam(3, w, h);
    cam.printConfig();

    cout << "Compare mode0 vs mode2: "
         << (cam.isHigherResolution(0, 2) ? "Mode0 higher" : "Mode2 higher") << "\n";

    cout << "Global compare: "
         << (globalCompareResolution(cam, 0, 2) ? "Mode0 higher" : "Mode2 higher") << "\n";

    return 0;
}
