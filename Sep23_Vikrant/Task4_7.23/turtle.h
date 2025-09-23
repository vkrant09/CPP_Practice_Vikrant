#ifndef TURTLE_H
#define TURTLE_H

#include <array>

class Turtle {
private:
    static const int floorSize = 20;
    std::array<std::array<bool, floorSize>, floorSize> floor;

    int row;
    int col;
    bool penDown;
    int direction; // 0 = right, 1 = down, 2 = left, 3 = up

public:
    Turtle();

    void penUp();
    void penDownAction();
    void turnRight();
    void turnLeft();
    void moveForward(int steps);
    void printFloor() const;
};

#endif
