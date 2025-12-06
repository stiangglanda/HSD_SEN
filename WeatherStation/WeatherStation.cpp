///////////////////////////////////////////////////////////////////////////
// Workfile : WeatherStation.cpp
// Author : Leander Kieweg
// Date : 06. 12. 2025
// Description : Weather Station module
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include "WeatherStation.h"
#include <iostream>

using namespace std;

// ---------------------------------------------------------
// Hilfsfunktion: Nur in dieser Datei sichtbar.
// Übernimmt das Formatieren einer einzelnen Station.
// ---------------------------------------------------------
static void PrintElement(TElement const & el) {
    cout << "Station:  " << el.name << endl;
    cout << "Celsius:  " << el.celsius << " Grad" << endl;
    cout << "Pressure: " << el.pressure << " mBar" << endl;
    cout << endl;
}

void Init(TWeatherStations &stations) {
    stations.numberOfStations = 0;
}

bool Insert(TWeatherStations &stations, string const &name, int const celsius, size_t const pressure) {
    if (IsFull(stations)) {
        return false;
    }
    stations.station[stations.numberOfStations].name = name;
    stations.station[stations.numberOfStations].celsius = celsius;
    stations.station[stations.numberOfStations].pressure = pressure;
    stations.numberOfStations++;
    return true;
}

bool Remove(TWeatherStations &stations, string const &name) {
    for (size_t i = 0; i < stations.numberOfStations; i++) {
        if (stations.station[i].name == name) {
            for (size_t j = i; j < stations.numberOfStations - 1; j++) {
                stations.station[j] = stations.station[j + 1];
            }
            stations.numberOfStations--;
            return true;
        }
    }
    return false;
}

bool IsEmpty(TWeatherStations const &stations) {
    return stations.numberOfStations == 0;
}

bool IsFull(TWeatherStations const &stations) {
    return stations.numberOfStations >= maxLen;
}

size_t GetNumberOfEntries(TWeatherStations const &stations) {
    return stations.numberOfStations;
}

void PrintAllStations(TWeatherStations const &stations) {
    for (size_t i = 0; i < stations.numberOfStations; i++) {
        PrintElement(stations.station[i]);
    }
}

bool PrintStation(TWeatherStations const &stations, string const &name) {
    for (size_t i = 0; i < stations.numberOfStations; i++) {
        if (stations.station[i].name == name) {
            PrintElement(stations.station[i]);
            return true;
        }
    }
    return false;
}

bool PrintColdestStation(TWeatherStations const &stations) {
    if (IsEmpty(stations)) {
        return false;
    }

    int minTemp = stations.station[0].celsius;
    for (size_t i = 1; i < stations.numberOfStations; i++) {
        if (stations.station[i].celsius < minTemp) {
            minTemp = stations.station[i].celsius;
        }
    }

    cout << "Coldest Station(s) " << minTemp << " Grad" << endl;
    for (size_t i = 0; i < stations.numberOfStations; i++) {
        if (stations.station[i].celsius == minTemp) {
            PrintElement(stations.station[i]);
        }
    }
    return true;
}

bool PrintWarmestStation(TWeatherStations const &stations) {
    if (IsEmpty(stations)) {
        return false;
    }

    int maxTemp = stations.station[0].celsius;
    for (size_t i = 1; i < stations.numberOfStations; i++) {
        if (stations.station[i].celsius > maxTemp) {
            maxTemp = stations.station[i].celsius;
        }
    }

    cout << "Warmest Station(s) " << maxTemp << " Grad" << endl;
    for (size_t i = 0; i < stations.numberOfStations; i++) {
        if (stations.station[i].celsius == maxTemp) {
            PrintElement(stations.station[i]);
        }
    }
    return true;
}