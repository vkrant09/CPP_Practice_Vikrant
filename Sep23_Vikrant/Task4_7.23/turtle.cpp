#include "turtle.h"
#include <iostream>

Turtle::Turtle() : row(0), col(0), penDown(false), direction(0) {
    for (auto &r : floor) {
        r.fill(false);
    }
}

void Turtle::penUp() {
    penDown = false;
}

void Turtle::penDownAction() {
    penDown = true;
}

void Turtle::turnRight() {
    direction = (direction + 1) % 4;
}

void Turtle::turnLeft() {
    direction = (direction + 3) % 4;
}

void Turtle::moveForward(int steps) {
    for (int i = 0; i < steps; i++) {
        if (penDown) {
            floor[row][col] = true;
        }

        switch (direction) {
        case 0: // right
            if (col < floorSize - 1) {
                col++;
            }
            break;
        case 1: // down
            if (row < floorSize - 1) {
                row++;
            }
            break;
        case 2: // left
            if (col > 0) {
                col--;
            }
            break;
        case 3: // up
            if (row > 0) {
                row--;
            }
            break;
        default:
            break;
        }
    }
}

void Turtle::printFloor() const {
    for (int r = 0; r < floorSize; r++) {
        for (int c = 0; c < floorSize; c++) {
            std::cout << (floor[r][c] ? '*' : ' ');
        }
        std::cout << '\n';
    }
}
