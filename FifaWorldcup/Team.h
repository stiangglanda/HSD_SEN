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
    // Initializes a team with the given name
    explicit Team(const std::string& name);

    // Adds match results and updates points and goals
    void addMatch(size_t goals_scored, size_t goalsConceded);

    // Returns the name of the team
    std::string getName() const;
    // Returns the number of goals conceded
    size_t getGoalsConceded() const;
    // Returns the number of goals scored
    size_t getGoalsScored() const;
    // Returns the total points
    size_t getPoints() const;
    // Returns the total number of matches played
    size_t getMatches() const;
    // Calculates and returns the goal difference
    int getGoalDifference() const;

    // Prints the team's data for the group table
    void Print(std::ostream& ost = std::cout) const;
    // Prints the team's name and goal difference
    void PrintNegativeDifferenceStyle(std::ostream& ost = std::cout) const;

    // Compares teams for sorting (points, diff, goals)
    bool operator<(const Team& other) const;
    // Streams the team's data
    friend std::ostream& operator<<(std::ostream& os, const Team& team);

private:
    std::string mName;
    size_t mMatches = 0;
    size_t mGoalsScored = 0;
    size_t mGoalsConceded = 0;
    size_t mPoints = 0;
};

#endif
