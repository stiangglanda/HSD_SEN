#ifndef MATRIX_H
#define MATRIX_H

#define MATRIX_SIZE 3

typedef int Matrix[MATRIX_SIZE][MATRIX_SIZE];

void inputMatrix(Matrix result);
void printMatrix(const Matrix m);
void addMatrices(const Matrix a, const Matrix b, Matrix result);
void multiplyMatrices(const Matrix a, const Matrix b, Matrix result);

#endif