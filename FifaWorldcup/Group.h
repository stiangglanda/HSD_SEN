///////////////////////////////////////////////////////////////////////////
// Workfile : Group.h
// Author : Leander Kieweg
// Date : 26.04.2026
// Description : Group Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef GROUP_H
#define GROUP_H
#include <string>
#include <vector>
#include "Team.h"

class Group {
public:
    // Initializes a group with the given name
    explicit Group(const std::string& name);
    // Adds a team to the group
    void AddTeam(const Team& team);
    // Sorts the teams in the group based on their rankings
    void Sort();
    // Prints the group's ranking table
    void Print(std::ostream& ost = std::cout) const;
    // Extracts teams with a negative goal difference into the result vector
    void ExtractNegativeDifferenceTeams(std::vector<Team>& result) const;

    // Streams the group's formatted data
    friend std::ostream& operator<<(std::ostream& os, const Group& group);

private:
    std::string mName;
    std::vector<Team> mTeams;
};

#endif
