#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "Tournament.h"


// error messages for parsing
const std::string MSG_EXPECTED_TEAM_NAME = "Parsing Error: Expected string for team name.";
const std::string MSG_EXPECTED_GOALS = "Parsing Error: Expected integer for scored goals.";
const std::string MSG_EXPECTED_GOALS_COLON = "Parsing Error: Expected integer for conceded goals after colon.";
const std::string MSG_UNEXPECTED_CHAR = "Parsing Error: Unexpected character after match result. Expected ',', '/', or ')'.";


// Scanner-based parser for the group block
void Tournament::ParseGroup(pfc::scanner& sc) {
	if (!sc.is_identifier()) return;

	std::string const groupNameStr = sc.get_identifier();

	sc.next_symbol(); // consume identifiers
	sc.next_symbol('(');

	bool groupEnd = false;
	while (!groupEnd && sc.has_symbol()) {

		if (!sc.is_string()) {
			throw std::runtime_error(MSG_EXPECTED_TEAM_NAME);
		}
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
	}
}


void Tournament::Parse(const std::string& data) {
	std::istringstream is(data);
	pfc::scanner sc(is);

	while (sc.has_symbol()) {
		ParseGroup(sc);
	}
}


void Tournament::Print(std::ostream& os) const {
	// TO DO
}
