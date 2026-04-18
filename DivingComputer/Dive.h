///////////////////////////////////////////////////////////////////////////
// Workfile : Dive.h
// Author : Leander Kieweg
// Date : 18.04.2026
// Description : Dive Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef DIVE_H
#define DIVE_H
#include <iostream>
#include <vector>
#include <string>

struct DiveEntry {
    size_t time; // in seconds
    double depth; // in meters
};

class Dive {
public:
    // Creates an empty dive.
    Dive() = default;

    // Prints the dive statistics.
    void PrintStats(std::ostream& ost = std::cout) const;

    // Adds one entry and sorts the data.
    void PushBackDiveEntry(const DiveEntry& entry);
    // Creates one entry and sorts the data.
    void EmplaceBackDiveEntry(size_t time, double depth);
private:
    double CalcSpeed(const DiveEntry& curr, const DiveEntry& next) const;
    std::string FormatTime(size_t seconds) const;
    void Sort();

    std::vector<DiveEntry> diveStats;
};

#endif
