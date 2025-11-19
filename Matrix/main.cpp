#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	Matrix a = {};
	inputMatrix(a);
	printMatrix(a);

	cout << "Input Matrix:" << endl;

	cout << "Matrix b Result:" << endl;
	Matrix b = {};
	addMatrices(a, a, b);
	printMatrix(b);

	cout << "Multiplication Result:" << endl;
	Matrix c = {};
	multiplyMatrices(a, b, c);
	printMatrix(c);
	return 0;
}
