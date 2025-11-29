///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 21. 11. 2025
// Description : Test Driver for the Matrix module
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int getOpenIndex(string Text, int index) {
	int parenthesisPair=0;
	for (int i = index; i >= 0; i--) {
		if (Text[i] == ')') {
			parenthesisPair++; // Wir laufen in einen verschachtelten Ausdruck rein
		} else if (Text[i] == '(') {
			if (parenthesisPair == 0) {
				return i; // Gefunden!
			} else {
				parenthesisPair--; // Eine geschlossene Klammer wurde "aufgelöst"
			}
		}
	}
	return -1;
}

int getCloseIndex(string Text, int index) {
	int parenthesisPair=0;
	for (int i = index; i < Text.size(); i++) {
		if (Text[i] == '(') {
			parenthesisPair++; // Wir laufen in einen verschachtelten Ausdruck rein
		} else if (Text[i] == ')') {
			if (parenthesisPair == 0) {
				return i; // Gefunden!
			} else {
				parenthesisPair--; // Eine verschachtelte Klammer wurde geschlossen
			}
		}
	}
	return -1;
}

string SucheKlammern(string Text, int index) {
	int openIndex = getOpenIndex(Text, index);
	int CloseIndex = getCloseIndex(Text, index);

	if (openIndex == -1 && CloseIndex == -1) {
		return Text;
	}

	if (openIndex == -1 || CloseIndex == -1) {
		return "";
	}

	return Text.substr(openIndex, CloseIndex - openIndex);
}

int main()
{
	cout << SucheKlammern("a * (b + c * (d + 1)) / (e - 2)", 13);
	return 0;
}
