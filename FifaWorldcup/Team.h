///////////////////////////////////////////////////////////////////////////
// Workfile : Team.h
// Author : Leander Kieweg
// Date : 26.04.2026
// Description : Team Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>


class Team {
public:
    Team(const std::string& name) : mName(name) {};

    void addMatch(size_t goals_scored, size_t goalsConceded);

    std::string getName() const { return mName; };
    size_t getGoalsConceded() const { return mGoalsConceded; };
    size_t getGoalsScored() const { return mGoalsScored; };
    size_t getPoints() const { return mPoints; };
    size_t getMatches() const { return mMatches; };
    int getGoalDifference() const { return static_cast<int>(mGoalsScored - mGoalsConceded); };

    void Print(std::ostream& ost = std::cout) const;
    void PrintNegativeDifferenceStyle(std::ostream& ost = std::cout) const;

    bool operator<(const Team& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Team& team);

private:
    std::string mName;
    size_t mMatches = 0;
    size_t mGoalsScored = 0;
    size_t mGoalsConceded = 0;
    size_t mPoints = 0;
};

#endif
