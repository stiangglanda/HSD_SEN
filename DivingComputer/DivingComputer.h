///////////////////////////////////////////////////////////////////////////
// Workfile : DivingComputer.h
// Author : Leander Kieweg
// Date : 04.04.2026
// Description : Diving Computer Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef DIVINGCOMPUTER_H
#define DIVINGCOMPUTER_H
#include <iostream>
#include <vector>

struct DiveEntry {
    size_t time; // in seconds
    double depth; // in meters
};

class DivingComputer {
public:
    DivingComputer() = default;

    void PrintDiveStats(std::ostream& ost = std::cout) const;

    void PushBackDiveEntry(const DiveEntry& entry);
    void EmplaceBackDiveEntry(size_t time, double depth);
private:
    double CalcSpeed(const DiveEntry& curr, const DiveEntry& next) const;
    std::string FormatTime(size_t seconds) const;
    void Sort();

    std::vector<DiveEntry> diveStats;
};

#endif
