#include "Fraction.h"
using namespace std;

// Hilfsfunktion fuer den Testausdruck
void PrintTestResult(std::string const& testName, bool const result) {
   cout << testName << ": " << (result ? "OK" : "NOK") << endl;
}

// Test der Fraction-Klasse
void TestFraction() {

   // Standardkonstruktor
   // TO DO

   // Konstruktor mit Parametern
   // TO DO
   
   //Copy-Konstruktor
   // TO DO

   //Division durch 0
   // TO DO

   // Addition
   // TO DO

   // Multiplikation
  // TO DO

   // Vergleichsoperatoren
   // TO DO

   // Zuweisungsoperator
   // TO DO

   // Ausgabeoperator
   // TO DO

   //Operationen mischen
   // TO DO

   //implizite Typumwandlung
   // TO DO

   //Verhinderung der impliziten Typkonversion durch Angabe von explicit beim CTOR
   // TO DO
}


int main()
{
   cout << "--- Start Test Fraction ---" << endl;
   TestFraction();
   cout << "--- Test finished ---" << endl;
}