//
// Created by stiangglanda on 2026-04-26.
//

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

private:
    std::string mName;
    size_t mMatches = 0;
    size_t mGoalsScored = 0;
    size_t mGoalsConceded = 0;
    size_t mPoints = 0;
};

#endif
