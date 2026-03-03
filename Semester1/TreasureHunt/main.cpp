///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 10. 01. 2026
// Description : Treasure Hunt Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "TreasureHunt.h"

int main() {
    TMaze maze;
    int const mazeType = 0;
    int const startRow = 8;
    int const startCol = 0;

    InitMaze(maze, mazeType);

    std::cout << "Treasure Hunt" << std::endl;
    DumpMaze(maze);
    std::cout << std::endl;

    std::cout << "Start Maze " << mazeType << " At (" << startRow << ", " << startCol << ")" << std::endl;

    bool found = FindTreasure(maze, startRow, startCol);

    if (found) {
        std::cout << "Found Treasure" << std::endl;
    } else {
        std::cout << "No Treasure Found" << std::endl;
    }

    DumpMaze(maze);

    FreeMaze(maze);
    return 0;
}