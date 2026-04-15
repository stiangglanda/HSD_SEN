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
using TPoints = vector<size_t>; //Punkte auf die Uebungen
using TPointsSize = TPoints::size_type; //Groeszentyp der Punkte
using TPointValue = TPoints::value_type; //Wertetyp der Punkte -> size_t

//hier in der Demo nur eine Struktur -> sonst Klasse besser!!
struct StudentInfo {
   string name;
   TPoints points;
};

using TGroup = vector<StudentInfo>; // eine Studierendengruppe
using TGroupSize = TGroup::size_type;
using TStudent = TGroup::value_type;
using TGroupItorConst = TGroup::const_iterator;
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
static bool CompareAsc(TStudent const& lStud, TStudent const& rStud) {
   return lStud.name < rStud.name;
}

static bool CompareDesc(TStudent const& lStud, TStudent const& rStud) {
   return !CompareAsc(lStud, rStud);
}



///////////////////////////////////////////////////
// Anwendung von Iteratoren in den Printfunktionen
// Folie_Iteratoren.pdf
///////////////////////////////////////////////////

// TO DO

static void Print(TPoints const& points, ostream& ost = cout) {
   assert(ost.good() && !points.empty());
   //Ausgabe bis zum vorletzten Element
   copy(points.cbegin(), --points.cend(),ostream_iterator<TPointValue>(ost, ", "));
   cout << points.back(); //lifert eine Referenz auf das letzte Element
}

static void Print(TStudent const& stud, ostream& ost = cout) {
   assert(ost.good());

   ost << stud.name << ":\t";
   Print(stud.points, ost);
   ost << endl;
}

static void Print(TGroup const& group, ostream& ost = cout) {
   assert(ost.good());

   for (/*TStudent*/auto const& stud : group) {
      Print(stud, ost);
   }
}

// Print mit Iteratoren
static void Print(TGroupItorConst begin, TGroupItorConst end, ostream& ost = cout) {
   assert(ost.good());

   while (begin != end) {
      Print(*begin++, ost);
   }
}

///////////////////////////////////////////////////
// Extrahieren von Studenten mit zuwenig Punkten
// Folie_Löschen_und_Einfügen_von_Vektorelementen.pdf
///////////////////////////////////////////////////

// TO DO




// Testtreiber für Studierende
int main () 
{
   TPointsSize const cCount = 10;

   // Direkt initialisierte StudentInfo-Objekte
   StudentInfo s1{ "Max Mustermann", { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 } };
   StudentInfo s2{ "Albert Stein",   { 50, 60, 70, 80, 90, 100, 110, 120, 130, 140 } };
   StudentInfo s3{ "Susi Sorglos",   { 20, 30, 40, 50, 60, 70, 80, 90, 100, 110 } };

   //// Gruppe initialisieren mit Liste
   TGroup group{ s1, s2, s3 };
   try 
   {
      //TO DO
      sort(group.begin(), group.end(), CompareAsc); //das ist ein function pointer -> CompareAsc
      sort(group.begin(), group.end(), CompareDesc); //das ist ein function pointer -> CompareDesc

      cout << "alle ausgeben: " << endl;
      Print(group);

      cout << "alle bis auf den letzten: " << endl;
      Print(group.cbegin(), --group.cend());
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