#include <iostream>
#include "TreasureHunt.h"

int main() {
    TMaze maze;
    int const mazeType = 1;
    int const startRow = 8;
    int const startCol = 0;

    InitMaze(maze, mazeType);

    std::cout << "--- Labyrinth VOR der Suche ---" << std::endl;
    DumpMaze(maze);
    std::cout << std::endl;

    std::cout << "Starte Suche bei (" << startRow << ", " << startCol << ")..." << std::endl;

    bool found = FindTreasure(maze, startRow, startCol);

    if (found) {
        std::cout << ">>> Erfolg! Schatz gefunden. <<<" << std::endl;
    } else {
        std::cout << ">>> Leider kein Weg zum Schatz gefunden. <<<" << std::endl;
    }

    std::cout << std::endl << "--- Labyrinth NACH der Suche ---" << std::endl;
    DumpMaze(maze);

    FreeMaze(maze);
    return 0;
}