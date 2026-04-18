///////////////////////////////////////////////////////////////////////////
// Workfile : DivingComputer.h
// Author : Leander Kieweg
// Date : 18.04.2026
// Description : Diving Computer Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef DIVINGCOMPUTER_H
#define DIVINGCOMPUTER_H
#include <vector>

#include "Dive.h"

class DivingComputer {
public:
    // Adds one dive.
    void AddDive(const Dive& dive);
    // Prints all stored dives.
    void PrintAllDives(std::ostream& ost = std::cout) const;
    // Returns the number of stored dives.
    size_t GetDiveCount() const;
    // Returns the dive at the given index.
    const Dive& GetDive(size_t index) const;
private:
    std::vector<Dive> dives;
};

#endif
