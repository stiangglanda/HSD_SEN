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

class Dive {
public:
    // Creates an empty dive.
    Dive() = default;

    // Prints the dive statistics.
    void PrintStats(std::ostream& ost = std::cout) const;

    // Creates one entry and sorts the data.
    void EmplaceBackDiveEntry(size_t time, double depth);
private:
    struct DiveEntry {
        size_t time; // in seconds
        double depth; // in meters
    };

    double CalcSpeed(const DiveEntry& curr, const DiveEntry& next) const;
    std::string FormatTime(size_t seconds) const;
    void Sort();

    std::vector<DiveEntry> diveStats;
};

#endif
