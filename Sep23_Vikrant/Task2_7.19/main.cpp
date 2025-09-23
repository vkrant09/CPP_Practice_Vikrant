#include "craps.h"
#include <iostream>

int main() {
    CrapsGame game;
    game.playGames(1000);   // simulate 1000 games
    game.printStatistics(); 
    return 0;
}
