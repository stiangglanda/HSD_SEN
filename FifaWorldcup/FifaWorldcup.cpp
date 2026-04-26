///////////////////////////////////////////////////////////////////////////
// Workfile : FifaWorldcup.h
// Author : Leander Kieweg
// Date : 26.04.2026
// Description : Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <exception> // Für std::exception
#include <fstream>   // Für std::ofstream
#include "Tournament.h"


// error messages for exception handling
std::string const ERR_STANDARD = "An error occurred: ";
std::string const ERR_ALLOC = "Memory allocation failed: ";
std::string const ERR_SCAN = "Scanner error: ";
std::string const ERR_RUN = "Runtime error: ";
std::string const ERR_UNKNOWN = "An unknown error occurred!";



int main()
{

	// test data for parsing
	std::string inputDataNew =
		"A(\"Mexiko\"=2:1,1:1,3:0/\"Suedkorea\"=1:2,2:0,1:1/\"Suedafrika\"=0:1,1:1,0:2/\"Tschechien\"=1:1,0:2,2:0) "
		"B(\"Kanada\"=1:1,3:2,1:0/\"Schweiz\"=0:0,1:0,0:1/\"Katar\"=0:0,2:3,0:2/\"Bosnien\"=1:1,0:1,2:0) "
		"C(\"Brasilien\"=3:0,2:1,1:1/\"Marokko\"=1:2,2:0,1:0/\"Schottland\"=0:3,0:2,2:1/\"Haiti\"=0:1,0:1,1:2) "
		"D(\"USA\"=2:0,1:1,1:0/\"Australien\"=0:2,2:1,1:1/\"Paraguay\"=1:1,0:1,0:0/\"Tuerkei\"=0:1,1:2,0:0) "
		"E(\"Deutschland\"=2:1,3:2,1:1/\"Ecuador\"=0:0,2:3,0:2/\"Elfenbeinkueste\"=1:2,0:1,2:0/\"Curacao\"=0:0,1:0,1:1) "
		"F(\"Niederlande\"=2:0,1:0,3:1/\"Japan\"=0:2,1:1,2:1/\"Tunesien\"=0:1,1:1,0:1/\"Schweden\"=1:3,1:2,1:0) "
		"G(\"Belgien\"=3:0,2:0,1:1/\"Iran\"=0:3,1:0,1:1/\"Aegypten\"=0:2,0:1,2:1/\"Neuseeland\"=1:1,0:1,1:2) "
		"H(\"Spanien\"=2:1,1:1,3:0/\"Uruguay\"=1:2,2:0,1:1/\"Saudi-Arabien\"=0:1,1:1,0:2/\"Kap Verde\"=1:1,0:2,2:0) "
		"I(\"Frankreich\"=2:0,3:1,1:1/\"Senegal\"=1:1,2:1,0:2/\"Norwegen\"=0:2,1:2,2:0/\"Irak\"=1:1,0:2,0:2) "
		"J(\"Argentinien\"=1:1,3:1,3:0/\"Oesterreich\"=2:2,1:3,0:1/\"Algerien\"=1:1,3:1,1:0/\"Jordanien\"=2:2,1:3,0:3) "
		"K(\"Portugal\"=2:0,1:0,3:1/\"Kolumbien\"=0:2,1:1,2:1/\"Usbekistan\"=0:1,1:1,0:1/\"DR Kongo\"=1:3,1:2,1:0) "
		"L(\"England\"=2:1,1:1,3:0/\"Kroatien\"=1:2,2:0,1:1/\"Panama\"=0:1,1:1,0:2/\"Ghana\"=1:1,0:2,2:0)";

	Tournament tournament;

	try {
		std::cout << "--- Parse Daten ---\n";
		tournament.Parse(inputDataNew);

		std::cout << "--- Beispiel 1: Ausgabe der Gruppe ---\n";
		tournament.Print();

		std::cout << "\n--- Beispiel 2: Mannschaften extrahieren ---\n";
		std::cout << tournament.Extract();

		std::cout << "\n--- Fehlerbehandlung testen (Selbst implementierte Kantenfaelle) ---\n";

		std::cout << "Test 1: Fehlender Identifier zum Gruppenstart (MSG_EXPECTED_IDENTIFIER)...\n";
		Tournament fehlerTournament1;
		try {
			// Hier startet der String fälschlicherweise nicht mit einem Gruppen-Identifier wie 'A'
			fehlerTournament1.Parse("(\"Mexiko\"=2:1,1:1,3:0/)");
		} catch (const std::runtime_error& e) {
			std::cerr << "Erfolgreich gefangen: " << e.what() << "\n";
		}

		std::cout << "\nTest 2: Defekter Ausgabestream...\n";
		// Wir uebergeben einen Stream, der sich in einem bad()-State befindet, an eine Ausgabe
		std::ofstream badStream;
		badStream.setstate(std::ios::badbit); // Stream absichtlich in Fehlerzustand versetzen

		try {
			// Teste die ueberladenen Print/Operator-Methoden, die cErrStream werfen sollen
			tournament.Print(badStream);
		} catch (const std::runtime_error& e) {
			std::cerr << "Erfolgreich gefangen: " << e.what() << "\n";
		}

	} catch (const std::bad_alloc& e) {
		std::cerr << ERR_ALLOC << e.what() << '\n';
	} catch (const std::runtime_error& e) {
		std::cerr << ERR_RUN << e.what() << '\n';
	} catch (const std::exception& e) {
		std::cerr << ERR_STANDARD << e.what() << '\n';
	} catch (...) {
		std::cerr << ERR_UNKNOWN << '\n';
	}

	return 0;
}
