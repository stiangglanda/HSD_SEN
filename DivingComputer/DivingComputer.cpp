///////////////////////////////////////////////////////////////////////////
// Workfile : DivingComputer.cpp
// Author : Leander Kieweg
// Date : 04.04.2026
// Description : Test Driver for Date and Calendar
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "DivingComputer.h"

#include <ostream>

#include <format>
#include <sstream>
#include <iomanip>

// constants
const int col_width = 10;
const int col_spacing = 4;
const int depth_prec = 2;
const int speed_prec = 3;

std::ostream& sep(std::ostream& ost) {
    ost << std::string(col_spacing, ' ');
    return ost;
}

std::ostream& line(std::ostream& ost) {
    ost << std::string(3 * col_width + 2 * col_spacing, '-') << std::endl;
    return ost;
}

// helper: convert seconds → hh:mm:ss
std::string FormatTime(size_t seconds) {
    size_t h = seconds / 3600;
    size_t m = (seconds % 3600) / 60;
    size_t s = seconds % 60;

    return std::format("{:02}:{:02}:{:02}", h, m, s);
}

double DivingComputer::CalkUpDown(const DiveEntry& curr, const DiveEntry& next) {
    double dt = static_cast<double>(next.time - curr.time);
    double dd = next.depth - curr.depth;
    return dd / dt;
}

void DivingComputer::PrintDiveStats(std::ostream& ost) {

    ost << std::left
        << std::setw(col_width) << "Dive Time" << sep
        << std::setw(col_width) << "Dive Depth" << sep
        << std::setw(col_width) << "Down/Up"
        << std::endl;

    ost << std::left
        << std::setw(col_width) << "(hh:mm:ss)" << sep
        << std::setw(col_width) << "(m)"        << sep
        << std::setw(col_width) << "(m/sec)"
        << std::endl;

    ost << line;

    for (size_t i = 0; i < diveStats.size(); ++i) {
        const auto& curr = diveStats[i];

        ost << std::left
            << std::setw(col_width) << FormatTime(curr.time) << sep
            << std::setw(col_width) << std::setprecision(depth_prec) << curr.depth << sep
            << std::endl;

        if (i+1<diveStats.size()) {
            const auto& next = diveStats[i+1];
            ost << std::string(2 * col_width + 2 * col_spacing, ' ') << std::setprecision(depth_prec) << CalkUpDown(curr, next) << std::endl;
        }
    }
}

void DivingComputer::PushBackDiveEntry(DiveEntry entry) {
    diveStats.push_back(entry);
}

void DivingComputer::EmplaceBackDiveEntry(size_t time, double depth) {
    diveStats.emplace_back(time, depth);
}
