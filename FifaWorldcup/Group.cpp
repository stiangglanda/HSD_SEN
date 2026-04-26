//
// Created by stiangglanda on 2026-04-26.
//

#include "Group.h"
#include <algorithm>
#include <iomanip>

static std::string const cErrStream{ "output stream is faulty" };

static const int col_width_num = 2;
static const int col_spacing = 2;

static std::ostream& sep(std::ostream& ost) {
    ost << std::string(col_spacing, ' ');
    return ost;
}

void Group::AddTeam(const Team &team) {
    mTeams.push_back(team);
}

void Group::Sort() {
    std::sort(mTeams.begin(), mTeams.end(),SortTeam);
}

void Group::Print(std::ostream &ost) const {
    if (!ost.good()) {
        throw std::runtime_error(cErrStream);
    }
    ost << "Gruppe_" << mName << std::endl;
    ost << "--------" << std::endl;

    for (size_t i = 0; i < mTeams.size(); i++) {
        ost << std::right << std::setw(col_width_num) << i+1 << sep;
        mTeams[i].Print(ost);
    }
}

bool Group::SortTeam(const Team &teamA, const Team &teamB) {
    if (teamA.getPoints() != teamB.getPoints()) {
        return teamA.getPoints() > teamB.getPoints();
    }

    if (teamA.getGoalDifference() != teamB.getGoalDifference()) {
        return teamA.getGoalDifference() > teamB.getGoalDifference();
    }

    return teamA.getGoalsScored() > teamB.getGoalsScored();
}
