///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 11. 12. 2025
// Description : First Name Classification 
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

enum TName { eFemale, eMale };
TName AnalyseFirstname(string const& name)
{
	string namelower="";

	for (char c : name) {
		namelower += tolower(c);
	}

	if (namelower.empty()) {
		return eMale;
	}

	const string maleNames[] = { "leander", "maximilian", "lukas" };
	const string femaleNames[] = { "anna", "maria", "sofia", "kim", "ruth" };

	for (const string& m : maleNames) {
		if (namelower == m) {
			return eMale;
		}
	}

	for (const string& f : femaleNames) {
		if (namelower == f) {
			return eFemale;
		}
	}

	if (namelower.back() == 'a')
	{
		return eFemale;
	}

	return eMale;
}

int main () {
	string name = "Leander";

	cout << "Firstname classification Input: " << endl;
	cin >> name;
	switch (AnalyseFirstname(name))
	{
	case eFemale:
		cout << "Female name" << endl;
		break;
	case eMale:
		cout << "Male name" << endl;
		break;
	default:
		break;
	}

    return 0;
}
