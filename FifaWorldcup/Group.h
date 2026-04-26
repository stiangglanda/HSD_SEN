//
// Created by stiangglanda on 2026-04-26.
//

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

    friend std::ostream& operator<<(std::ostream& os, const Group& group);

private:
    std::string mName;
    std::vector<Team> mTeams;
};

#endif
