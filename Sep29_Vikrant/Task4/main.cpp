#include "race.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Seed random generator once for the whole game
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Starting positions
    int tortoisePos = 1;
    int harePos = 1;

    std::cout << "BANG !!!!!\n"
              << "AND THEY'RE OFF !!!!!\n";

    // Loop until someone reaches finish line (pos 70)
    while (tortoisePos < 70 && harePos < 70)
    {
        moveTortoise(&tortoisePos); // move tortoise
        moveHare(&harePos);         // move hare

        // cap positions at 70 (finish line)
        if (tortoisePos > 70) { tortoisePos = 70; }
        if (harePos > 70) { harePos = 70; }

        printTrack(tortoisePos, harePos); // print track
    }

    // Decide winner or tie
    if (tortoisePos >= 70 && harePos >= 70)
    {
        std::cout << "It's a tie. (But Tortoise is favored!)\n";
    }
    else if (tortoisePos >= 70)
    {
        std::cout << "TORTOISE WINS!!! YAY!!!\n";
    }
    else
    {
        std::cout << "Hare wins. Yuch.\n";
    }

    return 0;
}
