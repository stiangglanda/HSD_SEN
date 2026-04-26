///////////////////////////////////////////////////////////////////////////
// Workfile : Team.cpp
// Author : Leander Kieweg
// Date : 26.04.2026
// Description : Team Implementation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "Team.h"
#include <iomanip>

static std::string const cErrStream{ "output stream is faulty" };

static const int col_width_num = 4;
static const int col_width_name = 15;
const int col_spacing = 4;
const int points_win = 3;
const int points_draw = 1;

static std::ostream& sep(std::ostream& ost) {
    ost << std::string(col_spacing, ' ');
    return ost;
}

Team::Team(const std::string &name): mName(name) {}

void Team::addMatch(size_t goalsScored, size_t goalsConceded) {
    mMatches++;
    mGoalsConceded += goalsConceded;
    mGoalsScored += goalsScored;

    if (goalsScored > goalsConceded) { // Win
        mPoints += points_win;
    } else if (goalsScored == goalsConceded) { // Draw
        mPoints += points_draw;
    } // else = lost(+0 points)
}

std::string Team::getName() const { return mName; }

size_t Team::getGoalsConceded() const { return mGoalsConceded; }

size_t Team::getGoalsScored() const { return mGoalsScored; }

size_t Team::getPoints() const { return mPoints; }

size_t Team::getMatches() const { return mMatches; }

int Team::getGoalDifference() const { return static_cast<int>(mGoalsScored - mGoalsConceded); }

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

void Team::PrintNegativeDifferenceStyle(std::ostream &ost) const {
    if (!ost.good()) {
        throw std::runtime_error(cErrStream);
    }

    ost << std::left
        << std::setw(col_width_name) << mName
        << std::right << std::setw(col_width_num) << getGoalDifference()
        << std::endl;
}

bool Team::operator<(const Team& other) const {
    if (mPoints != other.mPoints) {
        return mPoints < other.mPoints;
    }
    if (getGoalDifference() != other.getGoalDifference()) {
        return getGoalDifference() < other.getGoalDifference();
    }
    return mGoalsScored < other.mGoalsScored;
}

std::ostream& operator<<(std::ostream& os, const Team& team) {
    team.Print(os);
    return os;
}
