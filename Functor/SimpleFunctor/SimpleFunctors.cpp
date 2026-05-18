#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cassert>
using namespace std;

//Hilfsfunktionalität
using TCont = vector<int>;

static ostream& operator << (ostream& ost, TCont const& cont)
{
   assert(ost.good());
   copy(cont.cbegin(), cont.cend(), ostream_iterator<TCont::value_type>{ost, " "});
   return ost << endl;
}

//Konstanten für die Berechnungen
static int const cMIN = 0;
static int const cMAX = 50;


int main()
{
	// AAA -> Almost Always Auto: Best Practice fuer die Deklaration von 
	// Variablen, da der Typ automatisch vom Compiler ermittelt wird. Es 
	// gibt keine Typkonvertierungen, da der Typ exakt bestimmt wird. Es 
	// ist auch moeglich, den Typ explizit anzugeben, z.B. auto<int>, aber 
	// das ist in der Regel nicht notwendig. Man wird gezwungen, die Variable 
	// sofort zu initialisieren (verhindert uninitialisierte Variablen)
	auto values = TCont{ 10, 60, 30, -20, -1, 0, 100 };
	auto values2 = TCont{ values };
   
  
}