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
	l.push_back(9);
	l.push_front(1);
	/*TIntList::const_iterator*/auto insPos = next(l.cbegin(),2); //liefert einen neuen Iterator an der Rinfuegeposition
	l.insert(insPos, 4711);
	Print(l, "after insertion");

	cout << l.size() << endl;
	cout << boolalpha << l.empty() << noboolalpha << endl;

	l.pop_front();
	l.pop_back();
	cout << "first: " << l.front() << endl;
	cout << "back: " << l.back() << endl;

	//belibiges Element loeschen
	l.erase(next(l.cbegin(), l.size() / 2));

	Print(l, "after erase");

	l.sort();
	Print(l, "after sort");

	l.sort([](int a, int b) { return a > b; });
	Print(l, "after sort descending");

	l.clear();
	Print(l, "after clear");
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
	back_insert_iterator<TIntList> bInsItor(l);
	copy(v.cbegin(), v.cend(),bInsItor);

	// einfuegen via back_inserter-Funktion -> 
	// back_insert_iterator wird geliefert

	// TO DO
	copy(v.begin(), v.end(), back_inserter(l));

	//auch das ist moeglich
	bInsItor = 4711; //intressant ist quasi ein push_back
	Print(l, "after back_inserter");

	// fuer front_insert_iterator / front_inserter gilt die 
	// gleiche Vorgehensweise

	// TO DO
	copy(v.cbegin() + 1, v.cend(),front_inserter(l));

	// einfuegen an beliebiger Stelle via insert-iterator 

	//TO DO
	/*TIntList::iterator*/auto ins = next(l.begin(),3);

	// die ersten beiden Elemente vor Iterator ins einfuegen

	// TO DO
	copy(v.cbegin(), v.cbegin()+2,inserter(l, ins));

	// erzeugen des Insert-Iterators mit entsprechender 
	// Iteratorposition

	// TO DO
	insert_iterator<TIntList> insItor(l,ins);
	copy(v.cbegin(), v.cbegin()+2,insItor);

	insItor = 4712;
	Print(l, "after inserter");
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
	l.remove(2);
	Print(l, "after remove");

	// unique: Entfernt aufeinanderfolgende Duplikate

	// TO DO
	l.unique();
	Print(l, "after unique");

	// merge: Verschmilzt zwei sortierte Listen effizient

	// TO DO
	TIntList l2{2, 8, 6};
	l.sort();
	l2.sort();
	Print(l, "l after sort");
	Print(l2, "l2 after sort");

	l.merge(l2);
	Print(l, "l after merge");
	Print(l2, "l2 after merge");

	// splice: Knoten in O(1) umhaengen ohne Kopieren
	TIntList l3{ 98, 99 };

	// TO DO
	l.splice(++l.begin(), l3);
	Print(l, "l after splice");
	Print(l3, "l3 after splice");
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
	arr[0] = 4711;
	arr.at(1) = 4712;

	// SEHR WICHTIG fuer die Praxis: C-API Stringenz
	// data() liefert einen rohen Pointer (int*).
	// Das wird gebraucht, um arr an C-APIs zu uebergeben,
	// z.B. c_function(int* buffer, size_t len);

	// TO DO
	int* rawPtr = arr.data();
	cout << "access via data: " << rawPtr[1] << endl;

	cout << arr.size() << endl;
	cout << arr.front() << endl;
	cout << arr.back() << endl;

	// fill: Alle Elemente mit einem Wert fuellen

	// TO DO
	arr.fill(7);

	// Range-based for-loop
	
	// TO DO
	for (auto const val : arr) cout << val << " ";
	cout << endl;

	// Auch STL Algorithmen funktionieren mit std::array, da sie die notwendigen
	// Iteratoren bereitstellt. Hier z.B. copy:
	
	// TO DO
	copy(arr.cbegin(), arr.cend(), ostream_iterator<TArr::value_type>(cout, "@"));
	cout << endl;
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
