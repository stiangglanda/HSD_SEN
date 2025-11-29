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

int getOpenIndex(string Text, unsigned int index) {
	int parenthesisPair=0;
	for (int i = index; i >= 0; i--) {
		if (Text[i] == ')') {
			parenthesisPair++; // other parenthesis Pair
		} else if (Text[i] == '(') {
			if (parenthesisPair == 0) {
				return i; // Gefunden!
			} else {
				parenthesisPair--; // other parenthesis Pair is complete
			}
		}
	}
	return -1;
}

int getCloseIndex(string Text, unsigned int index) {
	int parenthesisPair=0;
	for (int i = index+1; i < Text.size(); i++) { //+1 ist wichtig
		if (Text[i] == '(') {
			parenthesisPair++; // other parenthesis Pair
		} else if (Text[i] == ')') {
			if (parenthesisPair == 0) {
				return i;
			} else {
				parenthesisPair--; // other parenthesis Pair is complete
			}
		}
	}
	return -1;
}

string SucheKlammern(string Text, int index) {
	if (index < 0 || index >= Text.size()) {
		return "";
	}

	int openIndex = getOpenIndex(Text, index);
	int CloseIndex = getCloseIndex(Text, index);

	if (openIndex == -1 && CloseIndex == -1) {
		return Text;
	}

	if (openIndex == -1 || CloseIndex == -1) {
		return "";
	}

	return Text.substr(openIndex, CloseIndex - openIndex+1);
}

int main()
{
	cout << SucheKlammern("a * (b + c * (d + 1)) / (e - 2)", 13)<<endl;
	cout << SucheKlammern("a * (b + c * (d + 1)) / (e - 2)", 11)<<endl;
	cout << SucheKlammern("a * (b + c * (d + 1)) / (e - 2)", 2)<<endl;
	cout << SucheKlammern("", 0)<<endl;
	cout << SucheKlammern("abc", 0)<<endl;
	cout << SucheKlammern("abc", 2)<<endl;
	cout << SucheKlammern("(a)", 1)<<endl;
	cout << SucheKlammern("((a))", 2)<<endl;
	cout << SucheKlammern("(a) + (b)", 6)<<endl;
	cout << SucheKlammern("(a + b", 1)<<endl;
	cout << SucheKlammern("a + b)", 1)<<endl;
	cout << SucheKlammern("(a + (b)", 4)<<endl;
	cout << SucheKlammern(")(", 1)<<endl;
	cout << SucheKlammern(")(", 0)<<endl;
	cout << SucheKlammern("(a)", 0)<<endl;
	cout << SucheKlammern("(a)", 2)<<endl;
	cout << SucheKlammern("test", -1)<<endl;
	cout << SucheKlammern("test", 4)<<endl;
	return 0;
}
