///////////////////////////////////////////////////////////////////////////
// Workfile : TreasureHunt.h
// Author : Leander Kieweg
// Date : 10. 01. 2026
// Description : Treasure Hunt Module Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#ifndef TREASUREHUNT_H
#define TREASUREHUNT_H

int const gSize = 15;
typedef char* TMaze[gSize];

void InitMaze(TMaze maze, int const type);
void DumpMaze(TMaze const maze);
bool FindTreasure(TMaze maze, int const i, int const j);
void FreeMaze(TMaze maze);

#endif