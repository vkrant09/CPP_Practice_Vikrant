#include <iostream>
using namespace std;

class LaneBoundary {
private:
    float curvature;
    int lane_id;

public:
    // constructor
    LaneBoundary(float c, int id) : curvature(c), lane_id(id) {}

    // getters
    float getCurvature() const { return curvature; }
    int getLaneId() const { return lane_id; }

    // compare curvature using this pointer
    bool compareCurvature(const LaneBoundary& other) const {
        return this->curvature > other.curvature;
    }

    // display details
    void display() const {
        cout << "Lane " << lane_id << " | Curvature: " << curvature << "\n";
    }
};

// global function
bool isCurvatureGreater(const LaneBoundary& l1, const LaneBoundary& l2) {
    return l1.getCurvature() > l2.getCurvature();
}

void printLaneComparison(const LaneBoundary& l1, const LaneBoundary& l2) {
    if (l1.getCurvature() > l2.getCurvature())
        cout << "Lane " << l1.getLaneId() << " has greater curvature.\n";
    else if (l2.getCurvature() > l1.getCurvature())
        cout << "Lane " << l2.getLaneId() << " has greater curvature.\n";
    else
        cout << "Both lanes have equal curvature.\n";
}

int main() {
    LaneBoundary lane1(0.015f, 1);
    LaneBoundary lane2(0.023f, 2);

    lane1.display();
    lane2.display();

    // compare using member
    cout << (lane1.compareCurvature(lane2) ? "Lane1 > Lane2\n" : "Lane1 <= Lane2\n");

    // compare using global
    printLaneComparison(lane1, lane2);

    return 0;
}
