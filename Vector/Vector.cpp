#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

// Fehlerkonstanten
static string const cErrOstream = "error in ostream";


// Ausgabe von Verwaltungsinformationen zum Vektor
static void PrintVecAdminInfo(vector<int> const& vect, string const& label = "")
{
	if (!label.empty())
	{
		cout << "--- " << label << " ---" << endl;
	}

	// TO DO
	cout << "vector empty: " << boolalpha << vect.empty() << endl;
	cout << "size: " << vect.size() << endl;
	cout << "max size: " << vect.max_size() << endl;
	cout << "capacity: " << vect.capacity() << endl;
	cout << "size of vector footprint: " << sizeof(vect) << " bytes" << endl << endl;
}

//Ieberladen des <<-Operators fuer vector<int>
static ostream& operator << (ostream& ost, vector<int> const& v) {
	// Iteration herkoemlich
	for (size_t i = 0; i < v.size(); ++i) {
		ost << v[i] << " ";
	}
	return ost << endl;
}


// --- Basis-Funktionen, Kapazitaet und Wachstum ---
static void DemonstrateBasicsAndCapacity()
{
	cout << "\n========== Demonstrate Basics and Capacity ==========\n";
	vector<int> vect{ 1, 2, 3 };

	// TO DO
	PrintVecAdminInfo(vect, "Initial Vector");
	vect.push_back(100);
	vect.push_back(200);
	PrintVecAdminInfo(vect, "After push_back");

	// Groesse setzen
	vect.resize(vect.size()*2, 666);
	cout << "After resize up: " << vect;
	vect.resize(vect.size()/4);
	cout << "After resize down: " << vect;
}



// --- Zugriff, Einfuegen und Iteration ---
static void DemonstrateInsertionAccessAndIteration()
{
	cout << "\n========== Demonstrate Insertion, Access and Iteration ==========\n";
	vector<int> vect{ 1, 2, 3, 4, 5 };

	// TO DO
}



// --- Loeschen und Manipulation ---
static void DemonstrateRemoveAndSwap()
{
	cout << "\n========== Demonstrate Remove and Swap ==========\n";
	vector<int> vect{ 10, 20, 30, 40, 50, 60, 70, 80, 90 };

	// TO DO
}



static void DemonstrateEmplaceAdvantage()
{
	// --- Vorteil von emplace_back zeigen ---
	// Dummy-Strukur zur Demonstration von emplace_back vs push_back
	struct Person {
		string name;
		int age;
		Person(string const& str, int const a) : name{ str }, age{ a } {
			cout << "  Constructed: " << name << endl;
		}
		Person(Person const& other) : name{ other.name }, age{ other.age } {
			cout << "  Copied: " << name << endl;
		}
	};

	cout << "\n========== Demonstrate emplace_back Advantage ==========\n";
	
	// TO DO
}



// --- Algorithmen: Median ---
static void DemonstrateAlgorithmsAndMedian()
{
	cout << "\n========== Demonstrate Algorithms: Median ==========\n";
	vector<int> numbers{ 12, 46, 1, 23, 6, 789, 234, 213 };

	// Definition eines Datentyps fuer die Groesse des Vektors
	// size_type ist ein Synonym fuer den Datentyp unsigned int, gross genug 
	// um die Anzahl an Elementen im groesstmoeglichen Vektor darzustellen.
	// Verwendung eingebauter STL-Datentypen ist guter Programmierstil. Es 
	// verhindert Probleme durch unterschiedliche std::vector-Implementierungen 
	// (z.B. Linux vs Windows).
	typedef vector<int>::size_type TVectorSize;  // alte C/C++ Variante

	// oder per using (moderne Variante -> nicht kompatibel 
	// mit alten Compilern)
	using TVectorSize = vector<int>::size_type;

	// Groesse des Vektors abfragen (Anzahl eingefuegter Elemente)
	TVectorSize const size = numbers.size();
	// oder
	// auto const size = numbers.size();

	// TO DO
}



int main()
{
	DemonstrateBasicsAndCapacity();
	DemonstrateInsertionAccessAndIteration();
	DemonstrateRemoveAndSwap();
	DemonstrateEmplaceAdvantage();
	DemonstrateAlgorithmsAndMedian();
}
