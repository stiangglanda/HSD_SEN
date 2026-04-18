///////////////////////////////////////////////////////////////////////////
// Workfile : DivingComputer.h
// Author : Leander Kieweg
// Date : 04.04.2026
// Description : Test Driver for Date and Calendar
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef DIVINGCOMPUTER_H
#define DIVINGCOMPUTER_H
#include <iosfwd>
#include <iostream>
#include <vector>

struct DiveEntry {
    size_t time; // in seconds
    double depth; // in meters
};

class DivingComputer {
public:
    DivingComputer() = default;

    double CalkUpDown(const DiveEntry& curr, const DiveEntry& next);

    void PrintDiveStats(std::ostream& ost = std::cout);

    void PushBackDiveEntry(DiveEntry entry);
    void EmplaceBackDiveEntry(size_t time, double depth);
private:

    std::vector<DiveEntry> diveStats;
};

#endif
