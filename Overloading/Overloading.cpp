#include <string>
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////
// Ueberladen von Funktionen durch unterschiedliche Schnittstellen
///////////////////////////////////////////////////////////////////
//
// Methoden die gleich heissen und eine unterschiedliche Schnittstelle 
// (Signatur) besitzen (Rueckgabewert gehoert nicht zur Signatur), 
// bezeichnet man als ueberladen. Sie koennen in unterschiedlichen 
// Aufrufsituationen auseinander gehalten werden. Der Aufruf erfolgt 
// entsprechend ihrer Schnittstelle.

// Bestimmung des Maximums zweier Zahlen
double Max(double const x, double const y)
{
   cout << "Max(double, double) aufgerufen" << endl;
   return x > y ? x : y;
}

// Bestimmung des Maximums zweier Zahlen
// Funktion mit gleichem Namen, aber unterschiedlicher Signatur
int Max(int const x, int const y)
{
   cout << "Max(int, int) aufgerufen" << endl;
   return x > y ? x : y;
}

// Maximum zweier Strings
string Max(string const& x, string const& y)
{
   cout << "Max(string const&, string const&) aufgerufen" << endl;
   return x > y ? x : y;
}

// Maximum zweier Strings
// Funktion mit gleichem Namen, aber unterschiedlicher Signatur 
// (Referenz statt const-Referenz)
string Max(string& x, string& y)
{
   cout << "Max(string&, string&) aufgerufen" << endl;
   return x > y ? x : y;
}

// Maximum von drei Zahlen - Ueberladung mit mehr Parametern
int Max(int const x, int const y, int const z)
{
   cout << "Max(int, int, int) aufgerufen" << endl;
   int temp = x > y ? x : y;
   return temp > z ? temp : z;
}

// Beispiel mit Default-Parametern (Alternative zu Ueberladung)
void printLine(string const& text, int count = 1)
{
   for (int i = 0; i < count; ++i) {
      cout << text;
   }
   cout << endl;
}

int main()
{
   cout << "=== Grundlegendes Ueberladen ===" << endl;
   double a = 1.2;
   double b = 3.37;
   int c = 1700;
   int d = 1000;

   cout << "Ergebnis: " << Max(a, b) << endl;
   cout << "Ergebnis: " << Max(c, d) << endl;
   cout << endl;

   cout << "=== Implizite Typkonvertierung ===" << endl;
   // float wird nach double konvertiert
   float pi = 3.14f;
   float e = 2.71f;
   cout << "Ergebnis: " << Max(pi, e) << endl;
   
   // char wird nach int konvertiert
   cout << "Ergebnis: " << Max(31, 'A') << " (31 vs 'A'=65)" << endl;
   cout << endl;

   cout << "=== String-Vergleich ===" << endl;
   // ACHTUNG: Literal-Strings muessen explizit zu string konvertiert werden!
   cout << "Ergebnis: " << Max(string("Max"), string("Moritz")) << endl;
   
   string str1 = "Max";
   string str2 = "Moritz";
   cout << "Ergebnis: " << Max(str2, str1) << endl;
   cout << endl;

   cout << "=== Ueberladung mit mehr Parametern ===" << endl;
   cout << "Ergebnis: " << Max(100, 200, 150) << endl;
   cout << endl;

   cout << "=== Default-Parameter als Alternative ===" << endl;
   printLine("Hallo", 3);
   printLine("Welt");  // verwendet Default count=1
   cout << endl;

   // FEHLERBEISPIEL (auskommentiert, da Compile-Fehler):
   // cout << Max(1, 2.5) << endl;  // FEHLER: Mehrdeutig! int oder double?
   // Loesung: Explizite Konvertierung
   cout << "=== Explizite Konvertierung bei Mehrdeutigkeit ===" << endl;
   cout << "Ergebnis: " << Max(1, static_cast<int>(2.5)) << endl;
   cout << "Ergebnis: " << Max(static_cast<double>(1), 2.5) << endl;

   return 0;
}