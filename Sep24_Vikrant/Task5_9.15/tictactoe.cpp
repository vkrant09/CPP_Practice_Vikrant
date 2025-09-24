#include "tictactoe.h"
#include <iostream>

TicTacToe::TicTacToe() : currentPlayer(1) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            board[r][c] = 0; // start empty
        }
    }
}

void TicTacToe::printBoard() const {
    std::cout << "\n";
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            char symbol = ' ';
            if (board[r][c] == 1) symbol = 'X';
            else if (board[r][c] == 2) symbol = 'O';

            std::cout << " " << symbol << " ";
            if (c < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (r < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

bool TicTacToe::makeMove(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        std::cout << "Invalid move. Try again.\n";
        return false;
    }
    if (board[row][col] != 0) {
        std::cout << "Square already taken. Try again.\n";
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

bool TicTacToe::checkWin() const {
    // check rows
    for (int r = 0; r < 3; r++) {
        if (board[r][0] != 0 &&
            board[r][0] == board[r][1] &&
            board[r][1] == board[r][2]) {
            return true;
        }
    }

    // check cols
    for (int c = 0; c < 3; c++) {
        if (board[0][c] != 0 &&
            board[0][c] == board[1][c] &&
            board[1][c] == board[2][c]) {
            return true;
        }
    }

    // check diagonals
    if (board[0][0] != 0 &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != 0 &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

bool TicTacToe::checkDraw() const {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] == 0) {
                return false; // still empty square
            }
        }
    }
    return !checkWin(); // full but no winner
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 1 ? 2 : 1);
}

int TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}
