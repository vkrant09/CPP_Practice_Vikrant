#include <iostream>
#include <unistd.h> // For usleep
#include "mazeTraverse.h"

// Directions: 0=up, 1=right, 2=down, 3=left
int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

// Print the maze
void printMaze(char maze[12][12]) {
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++)
            std::cout<<maze[i][j]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    usleep(100000); // 0.1 seconds pause for visualization
}

// Recursive function following right-hand-on-wall rule
bool mazeTraverseHelper(char maze[12][12], int row, int col, int dir) {
    // Mark current cell as path
    maze[row][col] = 'X';
    printMaze(maze);

    // Check if at exit (any boundary except starting point)
    if ((row == 0 || row == 11 || col == 0 || col == 11))
        return true;

    // Right-hand rule order: right, forward, left, back
    for(int i=0;i<4;i++){
        int newDir = (dir + 1 + i) % 4; // Turn right first
        int newRow = row + dRow[newDir];
        int newCol = col + dCol[newDir];

        if(maze[newRow][newCol]=='.'){
            if(mazeTraverseHelper(maze,newRow,newCol,newDir))
                return true;
        }
    }

    // Backtrack if stuck
    maze[row][col] = '.';
    printMaze(maze);
    return false;
}

// Wrapper function
void mazeTraverse(char maze[12][12], int startRow, int startCol) {
    if(!mazeTraverseHelper(maze,startRow,startCol,1)) // Start facing right
        std::cout<<"No exit found!"<<std::endl;
}
