///////////////////////////////////////////////////////////////////////////
// Workfile : WeatherStation.h
// Author : Leander Kieweg
// Date : 06. 12. 2025
// Description : Weather Station module
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H
#include <string>

struct TElement {
    std::string name; // Standort der Wetterstation.
    int celsius; // Temperatur in Grad Celsius.
    size_t pressure; // Luftdruck in mBar.
};

// Maximal zu verwaltende Stationen.
size_t const maxLen = 8;

// Array zum Ablegen der Struktur.
typedef TElement TElementArray[maxLen];

struct TWeatherStations {
    TElementArray station; // Array mit den Stationen.
    size_t numberOfStations; // Anzahl der Stationen im Array.
};

//-----------------------------------------------------------
// Initialisiert die Verwaltung 'stations' zu Beginn
// auf 0 Stationen
//-----------------------------------------------------------
void Init(TWeatherStations & stations);

//-----------------------------------------------------------
// Fügt eine neue Station in die Verwaltung 'stations'
// ein. Liefert Funktionswert 'true' zurück, wenn dies
// möglich war, und 'false' sonst.
//-----------------------------------------------------------
bool Insert(TWeatherStations & stations, std::string const & name, int const celsius, size_t const pressure);

//-----------------------------------------------------------
// Entfernt die Station mit Standort 'name' aus der
// Verwaltung. Die entstehende 'Lücke' in der Verwaltung ist
// zu schließen, sodass die Stationen fortlaufend sind.
// Liefert 'true' zurück, wenn die Station entfernt werden
// konnte; 'false' sonst.
//-----------------------------------------------------------
bool Remove(TWeatherStations & stations, std::string const & name);

//-----------------------------------------------------------
// Liefert als Funktionswert 'true', wenn keine Station
// enthalten ist; sonst 'false'
//-----------------------------------------------------------
bool IsEmpty(TWeatherStations const & stations);

//-----------------------------------------------------------
// Liefert als Funktionswert 'true', wenn die Verwaltung
// vollständig belegt ist; sonst 'false'
//-----------------------------------------------------------
bool IsFull(TWeatherStations const & stations);

//-----------------------------------------------------------
// Liefert die Anzahl der enthaltenen Stationen der
// Verwaltung zurück.
//-----------------------------------------------------------
size_t GetNumberOfEntries(TWeatherStations const & stations);

//-----------------------------------------------------------
// Gibt alle Stationen der Reihe nach formatiert am
// Bildschirm aus.
//-----------------------------------------------------------
void PrintAllStations(TWeatherStations const & stations);

//-----------------------------------------------------------
// Gibt nur die Station vom Standort 'name' am Bildschirm
// aus. Liefert 'true', wenn die Station enthalten ist,
// 'false' sonst.
//-----------------------------------------------------------
bool PrintStation(TWeatherStations const & stations, std::string const & name);

//-----------------------------------------------------------
// Gibt jene Station(en) inkl. Daten am Bildschirm aus, wo es
// am kältesten ist. Liefert 'false', wenn die Verwaltung leer
// ist; 'true' sonst.
//-----------------------------------------------------------
bool PrintColdestStation(TWeatherStations const & stations);

//-----------------------------------------------------------
// Gibt jene Station(en) inkl. Daten am Bildschirm aus, wo es
// am wärmsten ist. Liefert 'false', wenn die Verwaltung leer
// ist; 'true' sonst.
//-----------------------------------------------------------
bool PrintWarmestStation(TWeatherStations const & stations);

#endif