#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
private:
    int board[3][3];   // 0 = empty, 1 = player 1, 2 = player 2
    int currentPlayer; // whose turn

public:
    TicTacToe();

    void printBoard() const;
    bool makeMove(int row, int col); 
    bool checkWin() const;
    bool checkDraw() const;
    void switchPlayer();
    int getCurrentPlayer() const;
};

#endif
