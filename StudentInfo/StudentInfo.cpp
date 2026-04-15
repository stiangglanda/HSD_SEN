// ---------------------------------------------------------------------------------
// Das folgende Codestück behandelt die Themen: 
//	  * Sortieren mit Prädikat
//   * Extrahieren aus einem Container
//   * Anwendung der Iteratoren in den Printfunktionen

#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <assert.h>
using namespace std;


//Typdeklarationen -> verwenden von in Container eingebauten Datentypen

//TO DO


//////////////////////////
//Sortieren mit Prädikat
/////////////////////////
/*
Prädikat: ist eine Funktion, die einen booleschen Wahrheitswert liefert und
zwei Elemente im Container miteinander vergleicht.
Die Standardimplementierung von std::sort verwendet das Prädikat <.
Dieses Prädikat ist genau richtig, wenn es um den Vergleich von int oder double
etc. geht. Bei StudentInfos versagt es. Darum müssen wir uns ein entsprechendes
Prädikat selbst erzeugen:
*/

//Prädikat für Student

//TO DO



///////////////////////////////////////////////////
// Anwendung von Iteratoren in den Printfunktionen
// Folie_Iteratoren.pdf
///////////////////////////////////////////////////

// TO DO



///////////////////////////////////////////////////
// Extrahieren von Studenten mit zuwenig Punkten
// Folie_Löschen_und_Einfügen_von_Vektorelementen.pdf
///////////////////////////////////////////////////

// TO DO




// Testtreiber für Studierende
int main () 
{
   //TPointsSize const cCount = 10;

   // Direkt initialisierte StudentInfo-Objekte
   //StudentInfo s1{ "Max Mustermann", { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 } };
   //StudentInfo s2{ "Albert Stein",   { 50, 60, 70, 80, 90, 100, 110, 120, 130, 140 } };
   //StudentInfo s3{ "Susi Sorglos",   { 20, 30, 40, 50, 60, 70, 80, 90, 100, 110 } };

   //// Gruppe initialisieren mit Liste
   //TGroup group{ s1, s2, s3 };
   try 
   {
      
      
      //TO DO
   }
   catch (bad_alloc const& ex)
   {
      cerr << "memory allocation: " << ex.what() << endl;
      return 1;
   }
   catch (exception const& ex)
   {
      cerr << "standard exception: " << ex.what() << endl;
      return 1;
   }
   catch (...)
   {
      cerr << "unhandled exception" << endl;
      return 1;
   }
}