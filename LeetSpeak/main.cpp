///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 04. 12. 2025
// Description : Test Driver for the LeetSpeakConverter module
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "LeetSpeakConverter.h"

using namespace std;

int main()
{
	cout << "Leet Speak Converter Test Driver" << endl;
	string str = "123 !?";
	cout << endl << str << endl;
	ToLeet(str);
	cout << endl << str << endl;
	return 0;
}
