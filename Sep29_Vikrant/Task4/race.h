#ifndef RACE_H
#define RACE_H

#include <string>

// Function to move tortoise based on random roll
// Takes current position pointer and updates it
void moveTortoise(int* position);

// Function to move hare based on random roll
// Takes current position pointer and updates it
void moveHare(int* position);

// Prints the race track of size 70
// Shows T for tortoise, H for hare, OUCH!!! if both at same spot
void printTrack(int tortoisePos, int harePos);

#endif
