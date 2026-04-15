#include <iostream>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include "Exceptions.h"
#include "scanner.h"

using namespace std;

// Fehlerkonstanten fuer Exceptions
static string const cErrMedianEmptyCont{ "error -> median of an empty container." };
static string const cErrFile{ "error -> invalid file." };
static string const cErrFormat{ "error -> unknown file format" };
static string const cErrAvgEmptyCont{ "error -> average of an empty container" };
static string const cErrDivByZero{ "error -> division by zero" };


// Berechnung des Median
float Median(TCont cont) 
{
	TContSize const size = cont.size();
	TContSize const m = size / 2;

	std::sort(cont.begin(), cont.end());
	Print(cont);

	return ((size % 2) == 0) ?
		(cont.at(m) + cont.at(m - 1)) / 2.0f : cont.at(m);
}


// Ausgabe des conts
void Print(TCont const& cont, ostream& ost) 
{
	
	copy(cont.cbegin(), cont.cend(),
		std::ostream_iterator<TCont::value_type>(ost, " "));
	ost << std::endl;
}


// Einlesen der Werte mit Hilfe des Scanners
void ReadNumbers(TCont& cont) 
{
	ifstream file("Input.txt");

	pfc::scanner scan(file);
	while (!scan.is_eof()) {
		if (scan.is_integer()) {
			cont.push_back(scan.get_integer());
		}
		scan.next_symbol();
	}
}


// Berechnung des Durchschnittwertes der contelemente
double Average(TCont const& cont) 
{
	TContSize const n = cont.size();
	double sum = 0.0;
	
	for (int val : cont) {
		sum += val;
	}
	return sum / n;
}


// Fehlende ueberladene Average Funktion fuer die "Division by zero"
// Thematik in der Main.cpp
double Average(int const s, size_t const n) 
{
	return static_cast<double>(s) / n;
}


