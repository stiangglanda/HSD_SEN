///////////////////////////////////////////////////////////////////////////
// Workfile : Dive.cpp
// Author : Leander Kieweg
// Date : 18.04.2026
// Description : Dive Implementation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "Dive.h"
#include <algorithm>
#include <format>
#include <iomanip>
#include <stdexcept>

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
std::string Dive::FormatTime(size_t seconds) const {
    size_t h = seconds / 3600;
    size_t m = (seconds % 3600) / 60;
    size_t s = seconds % 60;

    return std::format("{:02}:{:02}:{:02}", h, m, s);
}

void Dive::Sort() {
    std::sort(diveStats.begin(), diveStats.end(),
        [](const DiveEntry& lhs, const DiveEntry& rhs) {
            return lhs.time < rhs.time;
        });
}

double Dive::CalcSpeed(const DiveEntry& curr, const DiveEntry& next) const {
    double dt = static_cast<double>(next.time - curr.time);
    if (dt==0) {
        throw std::domain_error("division by zero");
    }
    double dd = next.depth - curr.depth;
    return dd / dt;
}

void Dive::PrintStats(std::ostream& ost) const {

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
    ost << std::fixed;

    for (size_t i = 0; i < diveStats.size(); ++i) {
        const auto& curr = diveStats.at(i);

        ost << std::left
            << std::setw(col_width) << FormatTime(curr.time) << sep
            << std::setw(col_width) << std::setprecision(depth_prec) << curr.depth << sep
            << std::endl;

        if (i+1<diveStats.size()) {
            double UpDown = CalcSpeed(curr, diveStats.at(i+1));
            ost << std::string(2 * col_width + 2 * col_spacing, ' ')
                << std::setprecision(speed_prec)
                << std::showpos << UpDown
                << std::noshowpos << std::endl;
        }
    }
}

void Dive::PushBackDiveEntry(const DiveEntry& entry) {
    diveStats.push_back(entry);
    Sort();
}

void Dive::EmplaceBackDiveEntry(size_t time, double depth) {
    diveStats.emplace_back(time, depth);
    Sort();
}
