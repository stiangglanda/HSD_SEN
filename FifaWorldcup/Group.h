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
    Group(const std::string& name) : mName(name) {};
    void AddTeam(const Team& team);
    void Sort();
    void Print(std::ostream& ost = std::cout) const;
    void ExtractNegativeDifferenceTeams(std::vector<Team>& result) const;

    friend std::ostream& operator<<(std::ostream& os, const Group& group);

private:
    std::string mName;
    std::vector<Team> mTeams;
};

#endif
