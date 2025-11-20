#include "Matrix.h"
#include <iostream>

using namespace std;

void inputMatrix(Matrix result) {
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			cout << "Enter element [" << i << "][" << j << "]: ";
			cin >> result[i][j];
		}
	}
}

void printMatrix(const Matrix m) {
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void addMatrices(const Matrix a, const Matrix b, Matrix result) {
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			result[i][j] = a[i][j] + b[i][j];
		}
	}
}

void multiplyMatrices(const Matrix a, const Matrix b, Matrix result) {
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			for (int k = 0; k < matrix_size; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}