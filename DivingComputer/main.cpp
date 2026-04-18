///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 18.04.2026
// Description : Test Driver for DivingComputer
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "DivingComputer.h"

void TestSingleDive() {
    std::cout << "========== TEST 1: Single Dive ==========" << std::endl;
    Dive singleDive;

    // Insert entries out of order to verify sorting
    std::cout << "Adding reference data (unsorted)" << std::endl;

    singleDive.EmplaceBackDiveEntry(150, 15.0);
    singleDive.PushBackDiveEntry({0, 0.0}); // Test PushBack variant
    singleDive.EmplaceBackDiveEntry(50, 6.8);
    singleDive.EmplaceBackDiveEntry(270, 23.88);
    singleDive.EmplaceBackDiveEntry(10, 2.5);

    singleDive.EmplaceBackDiveEntry(800, 26.0);
    singleDive.EmplaceBackDiveEntry(1235, 20.5);
    singleDive.EmplaceBackDiveEntry(1780, 15.8);
    singleDive.EmplaceBackDiveEntry(2345, 8.3);
    singleDive.EmplaceBackDiveEntry(3976, 0);

    std::cout << "PrintStats() output:" << std::endl;
    singleDive.PrintStats();
    std::cout << std::endl;
}

void TestDivingComputer() {
    std::cout << "========== TEST 2: DivingComputer & File Output ==========" << std::endl;

    DivingComputer computer;

    // Dive 1
    Dive dive1;
    dive1.EmplaceBackDiveEntry(0, 0.0);
    dive1.EmplaceBackDiveEntry(60, 5.0);
    dive1.EmplaceBackDiveEntry(120, 5.0);
    dive1.EmplaceBackDiveEntry(180, 0.0);

    // Dive 2
    Dive dive2;
    dive2.EmplaceBackDiveEntry(0, 0.0);
    dive2.EmplaceBackDiveEntry(100, 12.5);
    dive2.EmplaceBackDiveEntry(300, 12.5);
    dive2.EmplaceBackDiveEntry(450, 3.0);
    dive2.EmplaceBackDiveEntry(600, 0.0);

    computer.AddDive(dive1);
    computer.AddDive(dive2);

    std::cout << "Dive count: " << computer.GetDiveCount() << std::endl;

    std::cout << "--- Printing all dives to console ---" << std::endl;
    computer.PrintAllDives(std::cout);

    // File output
    std::cout << "--- Writing to divelog.txt ---" << std::endl;
    std::ofstream outFile("divelog.txt");
    if (outFile.is_open()) {
        computer.PrintAllDives(outFile);
        outFile.close();
        std::cout << "File saved successfully" << std::endl;
    } else {
        std::cerr << "Failed to open file" << std::endl;
    }
}

void TestExceptions() {
    std::cout << "========== TEST 3: Exceptions ==========" << std::endl;
    Dive errorDive;

    errorDive.EmplaceBackDiveEntry(10, 5.0);
    errorDive.EmplaceBackDiveEntry(10, 8.0);

    std::cout << "Testing division-by-zero at equal timestamps:" << std::endl;
    try {
        errorDive.PrintStats(); // Should throw
    } catch (const std::domain_error& e) {
        std::cout << "Caught as expected: " << e.what() << std::endl;
    }

    std::cout << "Testing out-of-bounds getter in DivingComputer:" << std::endl;
    DivingComputer comp;
    try {
        comp.GetDive(99); // Does not exist
    } catch (const std::out_of_range& e) {
        std::cout << "Caught as expected: " << e.what() << std::endl;
    }
}

int main() {
    TestSingleDive();
    TestDivingComputer();
    TestExceptions();

    return 0;
}