///////////////////////////////////////////////////////////////////////////
// Workfile : TestData.h
// Author : Leander Kieweg
// Date : 21.03.2026
// Description : TestData Module Header
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#ifndef TESTDATA_H
#define TESTDATA_H
#include <iostream>

struct Point3D {
    int x = 0;
    int y = 0;
    int z = 0;
};

// Generates Test Data according to the grammar rules
void GenerateTestData(size_t Amount, std::ostream& os, const int lo=0, const int hi=50);

// Prints the content of a stream in this case for the testdata
void PrintTestData(std::istream& in);

// parses the testdata using the scanner and returns it in a Point3D array and a count variable
Point3D* ScanTestData(std::istream& in, int& count);

// Prints Points if they match in at least one dimension
void PrintMatchingPoints(Point3D const * points, int n);

#endif