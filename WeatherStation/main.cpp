///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 06. 12. 2025
// Description : Test Driver for the WeatherStation module
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "WeatherStation.h"

using namespace std;

int main()
{
	cout << "### Testfälle" << endl;
	TWeatherStations ws;

	// Init
	Init(ws);
	cout << "- Init() Output: IsEmpty: " << boolalpha << IsEmpty(ws) << endl;

	// Insert
	Insert(ws, "Wien", 10, 1013);
	bool insertResult = Insert(ws, "Bregenz", -5, 1020);

	cout << "- Insert 2 Stations Output: " << insertResult << ", IsEmpty: " << IsEmpty(ws) << endl;
	// PrintAllStations
	cout << "- PrintAllStations Output: " << endl;
	PrintAllStations(ws);

	// IsFull
	Insert(ws, "Salzburg", 10, 1013);
	Insert(ws, "Innsbruck", -5, 1000);
	Insert(ws, "Graz", 15, 1000);
	Insert(ws, "Linz", 16, 1000);
	Insert(ws, "Klagenfurt", 17, 1000);
	Insert(ws, "Eisenstadt", 18, 1000);

	cout << "- IsFull (8 items) Output: " << IsFull(ws) << endl;

	// Insert Overflow
	bool overflowResult = Insert(ws, "OverflowCity", 99, 9999);
	cout << "- Insert 9th Item (Overflow) Output: " << overflowResult << endl;

	// PrintStation
	bool printStationResult = PrintStation(ws, "OverflowCity");
	cout << "- PrintStation OverflowCity Output: " << printStationResult << endl;
	printStationResult = PrintStation(ws, "Graz");
	cout << "- PrintStation Graz Output: " << printStationResult << endl;

	// PrintColdestStation
	cout << "- PrintColdestStation (Expect Innsbruck & Bregenz):" << endl;
	PrintColdestStation(ws);
	// PrintWarmestStation
	cout << "- PrintWarmestStation (Expect Eisenstadt):" << endl;
	PrintWarmestStation(ws);

	// Remove & GetNumberOfEntries
	bool removeResult = Remove(ws, "Wien");
	cout << "- Remove(Wien) Output: " << removeResult << ", Count: " << GetNumberOfEntries(ws) << endl;

	bool removeInvalid = Remove(ws, "GibtsNicht");
	cout << "- Remove(GibtsNicht) Output: " << removeInvalid << endl;

	return 0;
}
