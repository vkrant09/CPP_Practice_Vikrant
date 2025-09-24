#include "tictactoe.h"
#include <iostream>

int main() {
    TicTacToe game;
    int row, col;
    bool gameOver = false;

    std::cout << "Welcome to TicTacToe!\nPlayer 1 = X, Player 2 = O\n";

    while (!gameOver) {
        game.printBoard();
        std::cout << "Player " << game.getCurrentPlayer()
                  << " enter row and col (0-2): ";
        std::cin >> row >> col;

        if (!game.makeMove(row, col)) {
            continue; // invalid move, retry
        }

        if (game.checkWin()) {
            game.printBoard();
            std::cout << "Player " << game.getCurrentPlayer() << " wins!\n";
            gameOver = true;
        } else if (game.checkDraw()) {
            game.printBoard();
            std::cout << "It's a draw!\n";
            gameOver = true;
        } else {
            game.switchPlayer();
        }
    }

    return 0;
}
