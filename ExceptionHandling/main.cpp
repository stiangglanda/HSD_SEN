#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "Exceptions.h"

using namespace std;

// =========================================================================
// TEST DRIVER (Isolation of test cases)
// =========================================================================

// --- Test 1: Reading and Printing (Should work WITHOUT exception) ---
static void test_ReadAndPrint() {
	cout << "--- Test 1: ReadNumbers & Print ---" << endl;
	TCont Numbers;
	try {
		ReadNumbers(Numbers);
		Print(Numbers);
		cout << "average: " << Average(Numbers) << endl;
		cout << "median:  " << Median(Numbers) << endl;

		cout << "[PASS] Target functions executed without throwing any exceptions." << endl;
	}
	catch (std::exception const& error) {
		cerr << "[FAIL] Unexpected standard exception caught: "
			<< error.what() << endl;
	}
	catch (...) {
		cerr << "[FAIL] Unexpected UNKNOWN exception caught!" << endl;
	}
	cout << endl;
}


// --- Test 2: Average of an empty container (Expects std::domain_error) ---
static void test_AverageEmptyContainer() {
	cout << "--- Test 2: Average Empty Container ---" << endl;
	TCont emptyNumbers;
	try {
		double avg = Average(emptyNumbers);
		cout << "average: " << avg << endl;
		cerr << "[FAIL] Expected exception was not thrown!" << endl;
	}
	catch (std::domain_error const& error) {
		cout << "[PASS] Expected std::domain_error caught: " << error.what()
			<< endl;
	}
	catch (std::exception const& error) {
		cerr << "[FAIL] Caught WRONG standard exception: " << error.what()
			<< endl;
	}
	catch (...) {
		cerr << "[FAIL] Expected std::domain_error, but caught UNKNOWN exception!" << endl;
	}
	cout << endl;
}


// --- Test 3: Division by zero (Expects std::domain_error) ---
static void test_DivisionByZero() {
	cout << "--- Test 3: Division by zero ---" << endl;
	try {
		double result = Average(103, 0);
		cout << "average: " << result << endl;
		cerr << "[FAIL] Expected exception was not thrown!" << endl;
	}
	catch (std::domain_error const& error) {
		cout << "[PASS] Expected std::domain_error caught: " << error.what()
			<< endl;
	}
	catch (std::exception const& error) {
		cerr << "[FAIL] Caught WRONG standard exception: " << error.what()
			<< endl;
	}
	catch (...) {
		cerr << "[FAIL] Expected std::domain_error, but caught UNKNOWN exception!" << endl;
	}
	cout << endl;
}


// --- Test 4: Median of an empty container (Expects std::domain_error) ---
static void test_MedianEmptyContainer() {
	cout << "--- Test 4: Median Empty Container ---" << endl;
	TCont emptyNumbers;
	try {
		float result = Median(emptyNumbers);
		cout << "median:  " << result << endl;
		cerr << "[FAIL] Expected exception was not thrown!" << endl;
	}
	catch (std::domain_error const& error) {
		cout << "[PASS] Expected std::domain_error caught: " << error.what()
			<< endl;
	}
	catch (std::exception const& error) {
		cerr << "[FAIL] Caught WRONG standard exception: " << error.what()
			<< endl;
	}
	catch (...) {
		cerr << "[FAIL] Expected std::domain_error, but caught UNKNOWN exception!" << endl;
	}
	cout << endl;
}


// --- Test 5: Faulty output stream (Expects std::ios_base::failure) ---
static void test_OstreamFailure() {
	cout << "--- Test 5: Ostream Failure ---" << endl;
	TCont Numbers = { 42 };
	try {
		ofstream file{ "hello.txt" };
		file.setstate(ios::failbit);
		Print(Numbers, file);
		cerr << "[FAIL] Expected exception was not thrown!" << endl;
	}
	catch (std::ios_base::failure const& error) {
		cout << "[PASS] Expected std::ios_base::failure caught: " << error.what()
			<< endl;
	}
	catch (std::exception const& error) {
		cerr << "[FAIL] Caught WRONG standard exception: " << error.what()
			<< endl;
	}
	catch (...) {
		cerr << "[FAIL] Expected std::ios_base::failure, but caught UNKNOWN exception!" << endl;
	}
	cout << endl;
}


static void runTests() {
	cout << "=== STARTING EXCEPTION TESTS ===" << endl << endl;
	test_ReadAndPrint();
	test_AverageEmptyContainer();
	test_DivisionByZero();
	test_MedianEmptyContainer();
	test_OstreamFailure();
	cout << "=== ALL TESTS COMPLETED ===" << endl << endl;
}


// =========================================================================
// MAIN APPLICATION (Production code architecture)
// =========================================================================

static void runProductionCode() {
	cout << "=== STARTING PRODUCTION CODE ===" << endl;

	TCont Numbers;

	// Echter fachlicher Ablauf
	ReadNumbers(Numbers);
	cout << "Numbers read successfully." << endl;

	Print(Numbers);

	cout << "Average of numbers: " << Average(Numbers) << endl;
	cout << "Median of numbers:  " << Median(Numbers) << endl;

	// TO TO
}


int main() {
	// 1. Zuerst die isolierten Unit-Tests laufen lassen
	runTests();

	// 2. Danach der echte Programmablauf, der durch einen einzigen 
	//    globalen try-catch Block abgesichert ist.
	try {
		runProductionCode();
	}
	catch (std::exception const& e) {
		cerr << "\n[PRODUCTION FATAL ERROR] " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "\n[PRODUCTION FATAL ERROR] An unknown error occurred!" << endl;
		return 2;
	}

	return 0;
}



