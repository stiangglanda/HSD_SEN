///////////////////////////////////////////////////////////////////////////
// Workfile : Matrix.cpp
// Author : Leander Kieweg
// Date : 21. 11. 2025
// Description : Matrix module with general matrix utility functions
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include "Matrix.h"
#include <iostream>

using namespace std;

void inputMatrix(Matrix result) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			cout << "Enter element [" << i << "][" << j << "]: ";
			cin >> result[i][j];
		}
	}
}

void printMatrix(const Matrix m) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void addMatrices(const Matrix a, const Matrix b, Matrix result) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			result[i][j] = a[i][j] + b[i][j];
		}
	}
}

void multiplyMatrices(const Matrix a, const Matrix b, Matrix result) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			result[i][j] = 0;

			for (int k = 0; k < MATRIX_SIZE; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}