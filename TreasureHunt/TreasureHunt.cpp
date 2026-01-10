#include "TreasureHunt.h"
#include <cstring>
#include <iostream>
#include <string>
#include <cassert>

static char* strAlloc(const std::string str) {
    char* pResult = new(std::nothrow) char[gSize+1];
    if (pResult == nullptr)
    {
        std::cout << "Allocation returned nullptr" << std::endl;
        assert(false);
    }

    std::strncpy(pResult, str.c_str(), gSize);
    return pResult;
}

static bool IsValidCoordinate(int const x, int const y) {
    return x >= 0 && x < gSize && y >= 0 && y < gSize;
}

void InitMaze(TMaze maze, int const type) {
    switch (type) {
        case 0: // first maze
            maze[0] = strAlloc("+++++++++++++++");
            maze[1] = strAlloc("+     +++     +");
            maze[2] = strAlloc("+++ + +++  ++ +");
            maze[3] = strAlloc("+   + ++  +++ +");
            maze[4] = strAlloc("+   +         +");
            maze[5] = strAlloc("+ +++++++++ +++");
            maze[6] = strAlloc("+   +         +");
            maze[7] = strAlloc("+++ +   +++++ +");
            maze[8] = strAlloc("    +      ++ +");
            maze[9] = strAlloc("+++++ ++++++  +");
            maze[10]= strAlloc("+        +++ ++");
            maze[11]= strAlloc("+ ++++++++++ ++");
            maze[12]= strAlloc("+     X  +    +");
            maze[13]= strAlloc("+    +++   ++ +");
            maze[14]= strAlloc("+++++++++++++++");
            break;
        case 1: // second maze
            maze[0] = strAlloc("+++++++++++++++");
            maze[1] = strAlloc("+     +++     +");
            maze[2] = strAlloc("+++ + +++  ++ +");
            maze[3] = strAlloc("+   + ++  +++ +");
            maze[4] = strAlloc("+   +         +");
            maze[5] = strAlloc("+ +++++++++ +++");
            maze[6] = strAlloc("+   +         +");
            maze[7] = strAlloc("+++ +   +++++ +");
            maze[8] = strAlloc("    +      ++ +");
            maze[9] = strAlloc("+++++ ++++++  +");
            maze[10]= strAlloc("+        +++ ++");
            maze[11]= strAlloc("+ ++++++++++ ++");
            maze[12]= strAlloc("+     X+ +    +");
            maze[13]= strAlloc("+    +++   ++ +");
            maze[14]= strAlloc("+++++++++++++++");
            break;
        default:
            maze[0] = strAlloc("+++++++++++++++");
            maze[1] = strAlloc("+     +++     +");
            maze[2] = strAlloc("+++ + +++  ++ +");
            maze[3] = strAlloc("+   + ++  +++ +");
            maze[4] = strAlloc("+   +         +");
            maze[5] = strAlloc("+ +++++++++ +++");
            maze[6] = strAlloc("+   +         +");
            maze[7] = strAlloc("+++ +   +++++ +");
            maze[8] = strAlloc("    +      ++ +");
            maze[9] = strAlloc("+++++ ++++++  +");
            maze[10]= strAlloc("+        +++ ++");
            maze[11]= strAlloc("++++++++++++ ++");
            maze[12]= strAlloc("+     X+ +    +");
            maze[13]= strAlloc("+    +++   ++ +");
            maze[14]= strAlloc("+++++++++++++++");
    }
}

void DumpMaze(TMaze const maze) {
    for (int i = 0; i < gSize; i++) {
        std::cout << maze[i] << std::endl;
    }
}

bool FindTreasure(TMaze maze, int const i, int const j) {

    if (maze[i][j] == 'X') {
        return true;
    } else if (maze[i][j] == '+' || maze[i][j] == '.') {
        return false;
    } else {
        maze[i][j] = '.';

        return (IsValidCoordinate(i-1, j) && FindTreasure(maze, i-1, j)) || // up
               (IsValidCoordinate(i, j+1) && FindTreasure(maze, i, j+1)) || // right
               (IsValidCoordinate(i+1, j) && FindTreasure(maze, i+1, j)) || // down
               (IsValidCoordinate(i, j-1) && FindTreasure(maze, i, j-1));   // left
    }
}

void FreeMaze(TMaze maze) {
    for (int i = 0; i < gSize; i++) {
        delete[] maze[i];
        maze[i] = nullptr;
    }
}
