#ifndef MATRIX_H
#define MATRIX_H

const int matrix_size = 3;

typedef int Matrix[matrix_size][matrix_size];

void inputMatrix(Matrix result);
void printMatrix(const Matrix m);
void addMatrices(const Matrix a, const Matrix b, Matrix result);
void multiplyMatrices(const Matrix a, const Matrix b, Matrix result);

#endif