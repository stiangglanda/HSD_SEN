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

// Funktion zur Begrenzung von Werten in einer Sequenz
static int Replace(int const val) {
	if (val < cMIN) return cMIN;
	else if (val > cMAX) return cMAX;
	else return val;
}

// besser: Funktor als einfache Klasse: die Begrenzungswerte werden bei
// konstruktion eingestellt
class ReplaceRange {
public:
	ReplaceRange(int const l = cMIN, int const u = cMAX) :
		mCLower{l}, mCUpper{u} // konstante muessen via initializer list initialisiert werden
	{ }

	//Funktionsaufruf wird ueberladen und macht somit ein Objekt dieser Klasse
	// zu einem Funktionsobjekt (Funktor)
	int operator() (int const val) {
		if (val < cMIN) return cMIN;
		else if (val > cMAX) return cMAX;
		else return val;
	}

private:
	int const mCLower;
	int const mCUpper;
};

//Lambda ist ähnlich wie ein funktor
static auto repLambda = [lower = 21, upper = 29](int const val) {
	if (val < cMIN) return cMIN;
	else if (val > cMAX) return cMAX;
	else return val;
};

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
   
	transform(values.cbegin(), values.cend(), values.begin(), Replace);
	cout << values;

	auto repRange = ReplaceRange{ 20, 30 };
	transform(values.cbegin(), values.cend(), values.begin(), repRange);
	cout << values;

	transform(values.cbegin(), values.cend(), values.begin(), ReplaceRange{22,29});
	cout << values;

	//oder Variante mit for_each
	//for_each(values.cbegin(), values.cend(), repRange); -> funkt. nicht
	for_each(values2.begin(), values2.end(), [/*&*/](auto& val) {
		if (val < cMIN) val = cMIN;
		if (val > cMAX) val = cMAX;
	});
	cout << values2;

	// Verwendung mit Lambda -> Parameteruebergabe via CTor ist allerdings nicht moeglich
	transform(values.cbegin(), values.cend(), values.begin(), repLambda);
	cout << values;
}