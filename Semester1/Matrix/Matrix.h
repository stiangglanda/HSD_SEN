///////////////////////////////////////////////////////////////////////////
// Workfile : Matrix.h
// Author : Leander Kieweg
// Date : 21. 11. 2025
// Description : Matrix module with general matrix utility functions
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#ifndef MATRIX_H
#define MATRIX_H

const int MATRIX_SIZE = 3;

typedef double Matrix[MATRIX_SIZE][MATRIX_SIZE];

void inputMatrix(Matrix result);
void printMatrix(const Matrix m);
void addMatrices(const Matrix a, const Matrix b, Matrix result);
void multiplyMatrices(const Matrix a, const Matrix b, Matrix result);

#endif