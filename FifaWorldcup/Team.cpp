//
// Created by stiangglanda on 2026-04-26.
//

#include "Team.h"

#include <iomanip>

static std::string const cErrStream{ "output stream is faulty" };

static const int col_width_num = 4;
static const int col_width_name = 15;
const int col_spacing = 4;

static std::ostream& sep(std::ostream& ost) {
    ost << std::string(col_spacing, ' ');
    return ost;
}

void Team::addMatch(size_t goalsScored, size_t goalsConceded) {
    mMatches++;
    mGoalsConceded += goalsConceded;
    mGoalsScored += goalsScored;

    if (goalsScored > goalsConceded) { // Win
        mPoints+=3;
    } else if (goalsScored == goalsConceded) { // Draw
        mPoints++;
    } // else = lost(+0 points)
}

void Team::Print(std::ostream &ost) const {
    if (!ost.good()) {
        throw std::runtime_error(cErrStream);
    }

    ost << std::left
        << std::setw(col_width_name) << mName
        << std::right << std::setw(col_width_num) << mMatches
        << std::setw(col_width_num) << mGoalsScored
        << std::setw(col_width_num) << getGoalDifference()
        << std::setw(col_width_num) << mPoints
        << std::endl;
}
