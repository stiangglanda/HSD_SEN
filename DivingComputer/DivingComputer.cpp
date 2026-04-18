///////////////////////////////////////////////////////////////////////////
// Workfile : DivingComputer.cpp
// Author : Leander Kieweg
// Date : 18.04.2026
// Description : Diving Computer Implementation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "DivingComputer.h"

void DivingComputer::AddDive(const Dive &dive) {
    dives.push_back(dive);
}

void DivingComputer::PrintAllDives(std::ostream& ost) const {
    if (!ost.good()) {
        throw std::runtime_error("output stream is faulty");
    }

    for (size_t i = 0; i < dives.size(); ++i) {
        ost << "=== Dive " << (i + 1) << " ===" << std::endl;
        dives.at(i).PrintStats(ost);
        ost << std::endl;
    }
}

size_t DivingComputer::GetDiveCount() const {
    return dives.size();
}

const Dive& DivingComputer::GetDive(size_t index) const {
    if (index >= dives.size()) {
        throw std::out_of_range("Dive index out of bounds");
    }
    return dives.at(index);
}
