#include "matrix.h"
///Description: Simple Implementation of matrix multiply
// This applys for all matrix...
// it takes theta(n*n*n) time.
Matrix
SQUARE_MARTRIX_MULTIPLY(Matrix A, Matrix B)
{
  Matrix C = buildMatrix(N); // 2
  int i, j, k;
  for (i = 0; i < n; i++) // 3 every row in C
    for (j = 0; j < n; j++) { // 4 every row each elemnt in C
      C[i*n + j] = 0; // 5 Initialize of C
      for (k = 0; k < n; k++) { // 6
	C[i*n + j] = C[i*n + j] + A[i*n + k]*B[k*n + j]; // 7
      }
    }
  return C; // 8
}
