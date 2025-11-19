#ifndef MATRIX_H
#define MATRIX_H

#define MATRIX_SIZE 3

typedef int Matrix[MATRIX_SIZE][MATRIX_SIZE];

Matrix inputMatrix();
void printMatrix(const Matrix m);
Matrix addMatrices(const Matrix a, const Matrix b);
Matrix multiplyMatrices(const Matrix a, const Matrix b);

#endif