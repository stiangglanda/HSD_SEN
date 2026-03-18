#include <iostream>
#include "SimpleClass.h"
#include <iomanip> //fuer die vordefinierten Manipulatoren - setw, setprecision, etc

using namespace std;

//Fehlermeldungen
static string const cErrOstream = "error in Simple::Print(...)";
static string const cErrOstreamForm = "error in Simple::PrintFormated(...)";
static string const cErrWrite = "write error in Simple::PrintFormated(...)";

//eigene Manipulator-Funktion fuesr eine horizontale Linie
static ostream& hr (ostream& ost) {
   ost << "-------------------------------" << endl;
   return ost;
}

//manipulator fuer Eurobezeichnung
static ostream& euro (ostream& ost) {
   ost << "EUR " << "€" << setw(10) << fixed << setprecision(2);
   return ost;
}

Simple::Simple() :
   mFirstVal{0},
   mSecondVal {0},
   mPublicMember{0}
{
   //mFirstVal = 0;
   // ...

   //Testausgabe
   cout << "+++ object with address " << this << " created +++\n";
}

Simple::Simple(int const val1, int const val2) :
   mFirstVal{val1},
   mSecondVal {val2},
   mPublicMember{0}
{
   //Testausgabe
   cout << "+++ object with address " << this << " created +++\n";
}

Simple::Simple(Simple const &s) :
   mFirstVal{s.mFirstVal },
   mSecondVal {s.mSecondVal},
   mPublicMember{s.mPublicMember}
{
   //Testausgabe
   cout << "+++ object with address " << this << " copied +++\n";
}

Simple::~Simple() {
   //bleibt leer - nichts zu tun
   //testausgabe
   cout << "+++ object with address " << this << " destryed +++\n";
}

int Simple::GetFirstVal() const {
   return mFirstVal;
}

int Simple::GetSecondVal() const {
   return mSecondVal;
}

void Simple::SetFirstVal(int const val) {
   mFirstVal = val;
}

void Simple::SetSecondVal(int const val) {
   mSecondVal = val;
}

void Simple::Print(std::ostream &ost) const {
   if (!ost.good()) {
      cerr << cErrOstream << endl;
      return;
   }

   ost << "first value: " << mFirstVal << endl;
   ost << "second value: " << mSecondVal << endl;
   ost << hr << hr;

   if (ost.fail()) {
      cerr << cErrWrite << endl;
      return;
   }
}

void Simple::PrintFormated(std::ostream &ost) const {
   if (!ost.good()) {
      cerr << cErrOstream << endl;
      return;
   }

   //todo
   ost << euro << mFirstVal << endl;
   ost << euro << mSecondVal << endl;

   ost << setw(8) << setfill('x') << 4711 << endl;
   ost << setw(8) << left << 4711 << endl;

   //weitere Manipulatoren
   double const pi = 3.14159265358979323846;
   ost << scientific << pi << endl;
   ost << fixed << setprecision(3) << pi << endl;
   ost << hex << showbase << 255 << endl;
   ost << uppercase << scientific << pi << endl;

   OutputActStreamValues(ost << dec);

   if (ost.fail()) {
      cerr << cErrWrite << endl;
      return;
   }
}

int Simple::CalcSum() const {
   return mFirstVal + mSecondVal;
}

int Simple::CalcDiff() const {
   return mFirstVal - mSecondVal;
}

//ausgeben von Stream-Attributen: aktuelle Genauigkeit,
//Fuellzeichen, Feldbreite
void Simple::OutputActStreamValues(ostream& ost) const
{
   ost << endl;
   ost << "precision=" << ost.precision() << endl;
   ost << "fill=" << ost.fill() << endl;
   ost << "width=" << ost.width() << endl;

   //und noch weitere, wenn Zeit und Interesse
   ost << "eof=" << ost.eof() << endl;
   ost << "fail=" << ost.fail() << endl;
   ost << "good=" << ost.good() << endl;
   ost << "bad=" << ost.bad() << endl;
}

