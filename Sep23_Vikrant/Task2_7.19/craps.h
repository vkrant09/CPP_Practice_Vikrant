#ifndef CRAPS_H
#define CRAPS_H

#include <array>

class CrapsGame {
private:
    static constexpr int maxRollsTracked = 20;
    int wins[maxRollsTracked + 1];
    int losses[maxRollsTracked + 1];
    int totalGames;
    int totalRolls;

public:
    CrapsGame();

    void playGames(int numGames);
    void printStatistics() const;

private:
    int rollDice() const;
    void recordResult(bool win, int rollCount);
};

#endif
