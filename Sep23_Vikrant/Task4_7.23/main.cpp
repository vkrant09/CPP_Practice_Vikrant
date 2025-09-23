#include "turtle.h"
#include <iostream>
#include <vector>

int main() {
    Turtle turtle;

    // Example program from problem statement
    std::vector<std::pair<int, int>> commands = {
        {2, 0},   // Pen down
        {5, 12},  // Move 12
        {3, 0},   // Turn right
        {5, 12},  // Move 12
        {3, 0},   // Turn right
        {5, 12},  // Move 12
        {3, 0},   // Turn right
        {5, 12},  // Move 12
        {1, 0},   // Pen up
        {6, 0},   // Print
        {9, 0}    // End
    };

    for (auto &cmd : commands) {
        switch (cmd.first) {
        case 1:
            turtle.penUp();
            break;
        case 2:
            turtle.penDownAction();
            break;
        case 3:
            turtle.turnRight();
            break;
        case 4:
            turtle.turnLeft();
            break;
        case 5:
            turtle.moveForward(cmd.second);
            break;
        case 6:
            turtle.printFloor();
            break;
        case 9:
            std::cout << "Program ended.\n";
            return 0;
        default:
            std::cout << "Unknown command.\n";
            break;
        }
    }

    return 0;
}
