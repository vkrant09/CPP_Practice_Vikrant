#include "race.h"
#include <iostream>
#include <cstdlib>   // for rand
#include <ctime>     // for time

// Moves the tortoise according to rules
// Fast plod (+3), Slip (-6), Slow plod (+1)
void moveTortoise(int* position)
{
    int move = 1 + (std::rand() % 10); // roll between 1 and 10

    if (move >= 1 && move <= 5)        // 50% chance -> fast plod
    {
        *position += 3;
    }
    else if (move == 6 || move == 7)   // 20% chance -> slip
    {
        *position -= 6;
    }
    else                               // 30% chance -> slow plod
    {
        *position += 1;
    }

    if (*position < 1)                 // never go below start
    {
        *position = 1;
    }
}

// Moves the hare according to rules
// Sleep, big hop (+9), big slip (-12), small hop (+1), small slip (-2)
void moveHare(int* position)
{
    int move = 1 + (std::rand() % 10);

    if (move == 1 || move == 2)        // 20% chance -> sleep
    {
        // no movement
    }
    else if (move == 3 || move == 4)   // 20% chance -> big hop
    {
        *position += 9;
    }
    else if (move == 5)                // 10% chance -> big slip
    {
        *position -= 12;
    }
    else if (move >= 6 && move <= 8)   // 30% chance -> small hop
    {
        *position += 1;
    }
    else                               // 20% chance -> small slip
    {
        *position -= 2;
    }

    if (*position < 1)
    {
        *position = 1;
    }
}

// Prints race track of length 70
// Shows positions of tortoise and hare
// If both collide -> prints "OUCH!!!"
void printTrack(int tortoisePos, int harePos)
{
    for (int i = 1; i <= 70; ++i)
    {
        if (i == tortoisePos && i == harePos)
        {
            std::cout << "OUCH!!!";   // collision
            i += 6; // skip spaces because OUCH!!! takes 7 chars
        }
        else if (i == tortoisePos)
        {
            std::cout << "T";         // tortoise here
        }
        else if (i == harePos)
        {
            std::cout << "H";         // hare here
        }
        else
        {
            std::cout << " ";         // empty track
        }
    }
    std::cout << '\n';
}
