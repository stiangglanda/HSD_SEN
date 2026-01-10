#include <iostream>
#include "TreasureHunt.h"

int main() {
    TMaze maze;
    InitMaze(maze,1);
    DumpMaze(maze);
    FindTreasure(maze, 8, 0);
    DumpMaze(maze);
    FreeMaze(maze);
    return 0;
}