#include <iostream>
#include <exception>
#include <vector>

// Beispielklasse zur Simulation eines gr��eren Objekts
class A {
public:
	int const GetVal() const { return mVal; }
private:
	int const mVal = 4711;
	long mArr[1024] = {0}; // Simulierter Speicherverbrauch
};


// Demonstration: new mit/ohne Exception
static void TestNewHandling() {
	std::cout << "\n--- TestNewHandling ---\n";

	// Variante ohne Ausnahmebehandlung � kann std::bad_alloc werfen
	try {
		A* a1 = new A; // kann Exception werfen!
		std::cout << "new A successful (without nothrow)\n";
		delete a1;
	}
	catch (std::bad_alloc const& e) {
		std::cerr << "Error in new A: " << e.what() << "\n";
	}

	// Variante mit std::nothrow � gibt nullptr zurueck
	A* a2 = new(std::nothrow) A;
	if (a2 != nullptr) {
		std::cout << "new A successful (with nothrow)\n";
		delete a2;
	}
	else {
		std::cerr << "new A failed (with nothrow)\n";
	}
}


// Demonstration: Zugriff auf vector mit und ohne Exceptions
static void TestVectorAccess() {
	std::cout << "\n--- TestVectorAccess ---\n";

	std::vector<A> v; // leerer Vektor

	try {
		// Zugriff mit .at() -> loest out_of_range Exception aus
		std::cout << "Access using .at(3): ";
		std::cout << v.at(3).GetVal() << "\n";
	}
	catch (std::out_of_range const& e) {
		std::cerr << "Exception in .at(): " << e.what() << "\n";
	}

	// Zugriff mit [] -> kein Exception-Handling!
	std::cout << "Access using [3] (may crash!): ";
	std::cout << v[3].GetVal() << "\n"; // Undefiniertes Verhalten!

	// Zugriff per Iterator � auch gefaehrlich!
	std::cout << "Iterator access (cbegin + 3): ";
	std::cout << (v.cbegin() + 3)->GetVal() << "\n"; // Undefiniertes Verhalten!
}


// Demonstration: Speicher ueberlaufen lassen (fuehrt zu bad_alloc)
static void TestMemoryExhaustion() {
	std::cout << "\n--- TestMemoryExhaustion ---\n";
	try {
		std::vector<A> vec;
		A a;

		while (true) {
			vec.push_back(a); // irgendwann: std::bad_alloc
		}
	}
	catch (std::bad_alloc const& e) {
		std::cerr << "Memory full (bad_alloc): " << e.what() << "\n";
	}
}


// Demonstration: Funktion wirft Exception, behandelt sie aber nicht selbst
static void TestUnhandledException() {
	std::cout << "\n--- TestUnhandledException ---\n";

	std::vector<int> vec; // leerer Vektor

	// Kein try-catch hier!
	// Die folgende Zeile wird eine out_of_range Exception werfen
	std::cout << "Accessing vec.at(1) without local exception handling: ";
	std::cout << vec.at(1) << "\n"; // Exception wird bis main() weitergereicht
}


// Main mit allgemeinem try-catch-Block
int main() {
	try {
		TestNewHandling();
		TestVectorAccess();         // Hinweis: Absturzgefahr! Nur gezielt ausfuehren
		//TestMemoryExhaustion();  // Hinweis: Endlosschleife, nur zum Testen aktivieren
		//TestUnhandledException();     // Neu: Exception wird hier oben gefangen
	}
	catch (std::exception const& e) {
		std::cerr << "Caught standard exception: " << e.what() << "\n";
		return 1;
	}
	catch (...) {
		std::cerr << "Unknown exception occurred.\n";
		return 1;
	}

	std::cout << "\nProgram completed successfully without exception.\n";
	return 0;
}