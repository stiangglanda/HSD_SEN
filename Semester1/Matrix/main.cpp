///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 21. 11. 2025
// Description : Test Driver for the Matrix module
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	Matrix a = {}; // Initialisiert alles mit 0.0

	inputMatrix(a);

	cout << endl << "Input Matrix:" << endl;
	printMatrix(a);

	cout << endl << "Matrix b (a + a) Result:" << endl;
	Matrix b = {};
	addMatrices(a, a, b);
	printMatrix(b);

	cout << endl << "Multiplication Result (a * b):" << endl;
	Matrix c = {};
	multiplyMatrices(a, b, c);
	printMatrix(c);

	return 0;
}
