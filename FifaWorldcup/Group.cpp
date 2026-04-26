///////////////////////////////////////////////////////////////////////////
// Workfile : Group.cpp
// Author : Leander Kieweg
// Date : 26.04.2026
// Description : Group Implementation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "Group.h"
#include <algorithm>
#include <iomanip>

static const std::string cErrStream{ "output stream is faulty" };

static const int col_width_num = 2;
static const int col_spacing = 2;

static std::ostream& sep(std::ostream& ost) {
    ost << std::string(col_spacing, ' ');
    return ost;
}

Group::Group(const std::string &name): mName(name) {}

void Group::AddTeam(const Team &team) {
    mTeams.push_back(team);
}

void Group::Sort() {
    std::sort(mTeams.rbegin(), mTeams.rend());
}

void Group::Print(std::ostream &ost) const {
    if (!ost.good()) {
        throw std::runtime_error(cErrStream);
    }
    ost << "Gruppe_" << mName << std::endl;
    ost << "--------" << std::endl;

    for (size_t i = 0; i < mTeams.size(); i++) {
        ost << std::right << std::setw(col_width_num) << i+1 << sep;
        ost << mTeams.at(i);
    }
}

void Group::ExtractNegativeDifferenceTeams(std::vector<Team> &result) const {
    for (const auto& team: mTeams) {
        if (team.getGoalDifference() < 0) {
            result.emplace_back(team);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Group& group) {
    group.Print(os);
    return os;
}
