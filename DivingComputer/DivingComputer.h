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
    void AddDive(const Dive& dive);
    void PrintAllDives(std::ostream& ost = std::cout) const;
    size_t GetDiveCount() const;
    const Dive& GetDive(size_t index) const;
private:
    std::vector<Dive> dives;
};

#endif
