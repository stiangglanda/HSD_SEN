#include "TreasureHunt.h"

#include <cstring>
#include <iostream>
#include <stdbool.h>
#include <string>

static char* strAlloc(const std::string str) {
    char* pResult = new char[gSize];
    std::strcpy(pResult, str.c_str());
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

static bool FindTreasureRec(TMaze maze, int const i, int const j, int const starti, int const startj) {

    if (maze[i][j] == 'X') {
        return true;
    } else if (maze[i][j] == '+') {
        return false;
    } else if (maze[i][j] == ' ') {
        maze[i][j] = '.';

        DumpMaze(maze);

        return (IsValidCoordinate(i-1, j) && FindTreasureRec(maze, i-1, j, starti, startj)) ||
               (IsValidCoordinate(i, j+1) && FindTreasureRec(maze, i, j+1, starti, startj)) ||
               (IsValidCoordinate(i+1, j) && FindTreasureRec(maze, i+1, j, starti, startj)) ||
               (IsValidCoordinate(i, j-1) && FindTreasureRec(maze, i, j-1, starti, startj));
    }  else {
        return false;


        if (IsValidCoordinate(i-1,j) && maze[i-1][j] == ' '|| maze[i-1][j] == 'X') { //up
            DumpMaze(maze);
            return FindTreasureRec(maze, i-1, j, starti, startj);
        } else if (IsValidCoordinate(i,j+1) && maze[i][j+1] == ' '|| maze[i][j+1] == 'X') { //right
            DumpMaze(maze);
            return FindTreasureRec(maze, i, j+1, starti, startj);
        } else if (IsValidCoordinate(i+1,j) && maze[i+1][j] == ' '|| maze[i+1][j] == 'X') { //down
            DumpMaze(maze);
            return FindTreasureRec(maze, i+1, j, starti, startj);
        } else if (IsValidCoordinate(i,j-1) && maze[i][j-1] == ' ' || maze[i][j-1] == 'X') { //left
            DumpMaze(maze);
            return FindTreasureRec(maze, i, j-1, starti, startj);
        }
    }


    // else if (IsValidCoordinate(i,j+1) && maze[i][j+1] == '.') { //right // backtracking
    //     DumpMaze(maze);
    //     return FindTreasureRec(maze, i, j+1, starti, startj);
    // } else if (IsValidCoordinate(i-1,j) && maze[i-1][j] == '.') { //up
    //     DumpMaze(maze);
    //     return FindTreasureRec(maze, i-1, j, starti, startj);
    // } else if (IsValidCoordinate(i,j-1) && maze[i][j-1] == '.') { //left
    //     DumpMaze(maze);
    //     return FindTreasureRec(maze, i, j-1, starti, startj);
    // } else if (IsValidCoordinate(i+1,j) && maze[i+1][j] == '.') { //down
    //     DumpMaze(maze);
    //     return FindTreasureRec(maze, i+1, j, starti, startj);
    // }
}

bool FindTreasure(TMaze maze, int const i, int const j) {
    if (maze[i][j] == 'X') {
        return true;
    }
    maze[i][j] = '.';

    if (IsValidCoordinate(i-1,j) && maze[i-1][j] == ' ') { //up
        return FindTreasureRec(maze, i-1, j, i, j);
    } else if (IsValidCoordinate(i,j+1) && maze[i][j+1] == ' ') { //right
        return FindTreasureRec(maze, i, j+1, i, j);
    } else if (IsValidCoordinate(i+1,j) && maze[i+1][j] == ' ') { //down
        return FindTreasureRec(maze, i+1, j, i, j);
    } else if (IsValidCoordinate(i,j-1) && maze[i][j-1] == ' ') { //left
        return FindTreasureRec(maze, i, j-1, i, j);
    }
}

void FreeMaze(TMaze maze) {
    for (int i = 0; i < gSize; i++) {
        delete[] maze[i];
        maze[i] = nullptr;
    }
}
