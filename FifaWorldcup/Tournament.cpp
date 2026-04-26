#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "Tournament.h"

#include "Group.h"
#include "Team.h"


// error messages for parsing
const std::string MSG_EXPECTED_TEAM_NAME = "Parsing Error: Expected string for team name.";
const std::string MSG_EXPECTED_GOALS = "Parsing Error: Expected integer for scored goals.";
const std::string MSG_EXPECTED_GOALS_COLON = "Parsing Error: Expected integer for conceded goals after colon.";
const std::string MSG_UNEXPECTED_CHAR = "Parsing Error: Unexpected character after match result. Expected ',', '/', or ')'.";
const std::string MSG_EXPECTED_IDENTIFIER = "Parsing Error: is_identifier to be true at start of ParseGroup";
const std::string cErrStream{ "output stream is faulty" };


// Scanner-based parser for the group block
Group Tournament::ParseGroup(pfc::scanner& sc) {
	if (!sc.is_identifier()) {
		throw std::runtime_error(MSG_EXPECTED_IDENTIFIER);
	}

	std::string const groupNameStr = sc.get_identifier();
	Group group{groupNameStr};

	sc.next_symbol(); // consume identifiers
	sc.next_symbol('(');

	bool groupEnd = false;
	while (!groupEnd && sc.has_symbol()) {

		if (!sc.is_string()) {
			throw std::runtime_error(MSG_EXPECTED_TEAM_NAME);
		}

		Team team{sc.get_string()};
		sc.next_symbol();

		sc.next_symbol('=');

		bool teamEnd = false;
		while (!teamEnd && sc.has_symbol()) {
			if (!sc.is_integer()) throw std::runtime_error(MSG_EXPECTED_GOALS);
			int goals1 = sc.get_integer();
			sc.next_symbol();

			sc.next_symbol(':');

			if (!sc.is_integer()) throw std::runtime_error(MSG_EXPECTED_GOALS_COLON);
			int goals2 = sc.get_integer();
			sc.next_symbol();

			team.addMatch(goals1, goals2);

			if (sc.is(',')) {
				sc.next_symbol();
			}
			else if (sc.is('/')) {
				sc.next_symbol();
				teamEnd = true;
			}
			else if (sc.is(')')) {
				sc.next_symbol();
				teamEnd = true;
				groupEnd = true;
			}
			else {
				throw std::runtime_error(MSG_UNEXPECTED_CHAR);
			}
		}
		group.AddTeam(team);
	}
	return group;
}

std::ostream & operator<<(std::ostream &ost, const std::vector<Team> &teams) {
	if (!ost.good()) {
		throw std::runtime_error(cErrStream);
	}

	ost << "Mannschaften mit negativer Tordifferenz:" << std::endl;
	ost << "----------------------------------------" << std::endl;
	for (const auto& team : teams) {
		team.PrintNegativeDifferenceStyle(ost);
	}
	return ost;
}


void Tournament::Parse(const std::string& data) {
	std::istringstream is(data);
	pfc::scanner sc(is);

	while (sc.has_symbol()) {
		Group group = ParseGroup(sc);
		group.Sort();
		groups.push_back(group);
	}
}


void Tournament::Print(std::ostream& os) const {
	for (auto group: groups) {
		os << group;
	}
}

std::vector<Team> Tournament::Extract() const {
	std::vector<Team> teams;
	for (auto group: groups) {
		group.ExtractNegativeDifferenceTeams(teams);
	}

	std::sort(teams.begin(), teams.end(),
		[](const Team& a, const Team& b) -> bool {
			return a.getGoalDifference() < b.getGoalDifference();
		});

	return teams;
}
