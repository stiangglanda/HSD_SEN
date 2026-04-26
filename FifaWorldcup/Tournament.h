#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Group.h"
#include "scanner.h"

// Represents a tournament consisting of various groups and teams.
// Handles parsing tournament data, extracting team info, and printing results.
class Tournament {
public:
	// Parses the tournament data from a given formatted string.
	void Parse(const std::string& data);

	// Prints the parsed tournament information to the specified output stream.
	// Defaults to std::cout if no stream is provided.
	void Print(std::ostream& os = std::cout) const;

	// TO DO: Implementation of the `Extract` method, which extracts and returns the teams
	std::vector<Team> Extract() const;
private:
	// TO DO: Implementation of data structures for groups and teams -> use separate classes for Group and Team
	std::vector<Group> groups;

	// Parses an individual group block using the provided scanner.
	Group ParseGroup(pfc::scanner& sc);
};

std::ostream& operator<<(std::ostream& ost, const std::vector<Team>& teams);

