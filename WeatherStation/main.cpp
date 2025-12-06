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
	cout << "Weather Station Test Driver" << endl;
	TWeatherStations weatherStations;
	Init(weatherStations);
	cout << "IsEmpty: " << boolalpha << IsEmpty(weatherStations) << endl;

	Insert(weatherStations, "Steyr", 25, 44);
	PrintAllStations(weatherStations);

	Insert(weatherStations, "Linz", 26, 45);
	Insert(weatherStations, "Wels", 27, 46);
	PrintAllStations(weatherStations);

	Remove(weatherStations, "Linz");
	PrintAllStations(weatherStations);

	cout << "IsEmpty: " << boolalpha << IsEmpty(weatherStations) << endl;
	cout << "IsFull: " << boolalpha << IsFull(weatherStations) << endl;

	PrintStation(weatherStations,"Wels");
	PrintColdestStation(weatherStations);
	PrintWarmestStation(weatherStations);
	return 0;
}
