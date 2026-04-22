#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>
#include <array>
using namespace std;

using TIntList = list<int>;

// Print fuer std::list
static void Print(TIntList const& l, string const& header)
{
	cout << endl << header << endl;
	copy(l.cbegin(), l.cend(),
		ostream_iterator<TIntList::value_type>(cout, " "));
	cout << endl;
}


// 1. Basis-Operationen der Liste
static void TestBasicListOperations()
{
	cout << "\n======= Test: Basic Operations =======" << endl;
	TIntList l{ 1, 2, 3, 4 };

	//TO DO
}


// 2. Insert-Iteratoren
static void TestInsertIterators()
{
	cout << "\n======= Test: Insert Iterators =======" << endl;
	TIntList l;
	vector<int> v{ 1, 2, 3 };

	// einfuegen via back_insert_iterator -> Objekt wird 
	// selbst erzeugt

	//TO DO

	// einfuegen via back_inserter-Funktion -> 
	// back_insert_iterator wird geliefert

	// TO DO

	// fuer front_insert_iterator / front_inserter gilt die 
	// gleiche Vorgehensweise

	// TO DO

	// einfuegen an beliebiger Stelle via insert-iterator 

	//TO DO

	// die ersten beiden Elemente vor Iterator ins einfuegen

	// TO DO

	// erzeugen des Insert-Iterators mit entsprechender 
	// Iteratorposition

	// TO DO
}


// 3. Erweiterte C++ Listen-Operationen
static void TestAdvancedListOperations()
{
	cout << "\n======= Test: Advanced Operations ======="
		<< endl;
	TIntList l{ 1, 2, 2, 3, 3, 3, 4, 1, 5, 2 };
	Print(l, "Initial list:");

	// remove: Entfernt in O(n) alle Vorkommnisse

	// TO DO

	// unique: Entfernt aufeinanderfolgende Duplikate

	// TO DO

	// merge: Verschmilzt zwei sortierte Listen effizient

	// TO DO

	// splice: Knoten in O(1) umhaengen ohne Kopieren
	TIntList l3{ 98, 99 };

	// TO DO
}


// 4. Modern C++ Array
static void TestArray()
{
	cout << "\n========== Test: std::array ==========" << endl;

	// Sequenz fester Groesse (zur Compilezeit bekannt)
	size_t const cLEN = 3;
	using TArr = array<int, cLEN>;

	TArr arr{ 1, 2, 3 };

	// TO DO

	// SEHR WICHTIG fuer die Praxis: C-API Stringenz
	// data() liefert einen rohen Pointer (int*).
	// Das wird gebraucht, um arr an C-APIs zu uebergeben,
	// z.B. c_function(int* buffer, size_t len);

	// TO DO

	// fill: Alle Elemente mit einem Wert fuellen

	// TO DO

	// Range-based for-loop
	
	// TO DO

	// Auch STL Algorithmen funktionieren mit std::array, da sie die notwendigen
	// Iteratoren bereitstellt. Hier z.B. copy:
	
	// TO DO
}


int main()
{
	try
	{
		TestBasicListOperations();
		TestInsertIterators();
		TestAdvancedListOperations();
		TestArray();
	}
	catch (bad_alloc const& error)
	{
		cerr << "memory allocation: " << error.what() << endl;
		return 1;
	}
	catch (exception const& error)
	{
		cerr << "standard exception: " << error.what()
			<< endl;
		return 1;
	}
	catch (...)
	{
		cerr << "unhandled exception -> catch it/try again..."
			<< endl;
		return 1;
	}

	return 0;
}
