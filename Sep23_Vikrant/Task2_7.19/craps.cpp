#include "craps.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

CrapsGame::CrapsGame() : totalGames(0), totalRolls(0) {
    for (int i = 0; i <= maxRollsTracked; i++) {
        wins[i] = 0;
        losses[i] = 0;
    }
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

int CrapsGame::rollDice() const {
    int die1 = 1 + std::rand() % 6;
    int die2 = 1 + std::rand() % 6;
    return die1 + die2;
}

void CrapsGame::recordResult(bool win, int rollCount) {
    int index = (rollCount > maxRollsTracked) ? maxRollsTracked : rollCount;
    if (win) {
        wins[index]++;
    } else {
        losses[index]++;
    }
}

void CrapsGame::playGames(int numGames) {
    for (int g = 0; g < numGames; g++) {
        totalGames++;
        int rollCount = 1;
        int sum = rollDice();
        totalRolls++;

        // first roll rules
        if (sum == 7 || sum == 11) {
            recordResult(true, rollCount);
            continue;
        }
        if (sum == 2 || sum == 3 || sum == 12) {
            recordResult(false, rollCount);
            continue;
        }

        int point = sum;
        bool gameOver = false;
        while (!gameOver) {
            rollCount++;
            totalRolls++;
            sum = rollDice();

            if (sum == point) {
                recordResult(true, rollCount);
                gameOver = true;
            } else if (sum == 7) {
                recordResult(false, rollCount);
                gameOver = true;
            }
        }
    }
}

void CrapsGame::printStatistics() const {
    std::cout << "Results after " << totalGames << " games:\n\n";

    for (int i = 1; i <= maxRollsTracked; i++) {
        std::cout << "Roll " << i << ": Wins = " << wins[i]
                  << ", Losses = " << losses[i] << "\n";
    }
    std::cout << "After " << maxRollsTracked << " rolls: Wins = " << wins[maxRollsTracked]
              << ", Losses = " << losses[maxRollsTracked] << "\n\n";

    int totalWins = 0, totalLosses = 0;
    for (int i = 1; i <= maxRollsTracked; i++) {
        totalWins += wins[i];
        totalLosses += losses[i];
    }

    double winPercent = 100.0 * totalWins / totalGames;
    double avgLength = static_cast<double>(totalRolls) / totalGames;

    std::cout << "Chances of winning: " << winPercent << "%\n";
    std::cout << "Average game length: " << avgLength << " rolls\n";

    std::cout << "Observation: Chances of winning do not significantly improve with game length.\n";
}
