#ifndef MATRIX
#define MATRIX

#include <stdlib.h>
#include <stdio.h>
///Here we define it as a 3*3 Matrix
// And Matrix(i, j) Means line i, Column j
// And it corespond to Matrix(i*n + j), because
// we fill the matrix line by line, not column by column.
#define n 2
#define N 2*2

#define buildMatrix(num) malloc((num)*sizeof(int));

typedef int* Matrix;

static void
printMatrix(Matrix A, int k)
{
  int i, j;
  for (i = 0; i < k; i ++ ) {
    for (j = 0; j < k; j++)
      printf("%d ", A[i*k + j]);
    printf("\n");
  }
}

static Matrix
MATRIX_ADD(Matrix A, Matrix B, int k)
{
  int i;
  Matrix C = buildMatrix(k*k);
  for (i = 0; i < k*k; i++)
    C[i] = A[i] + B[i];
  return C;
}

static Matrix
MATRIX_SUBSTRACT(Matrix A, Matrix B, int k)
{
  int i;
  Matrix C = buildMatrix(k*k);
  for (i = 0; i < k*k; i++)
    C[i] = A[i] - B[i];
  return C;
}
#endif // MATRIX
