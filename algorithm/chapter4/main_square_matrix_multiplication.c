#include "matrix.h"

extern Matrix SQUARE_MARTRIX_MULTIPLY(Matrix A, Matrix B);
int
main(int argc, char* argv[])
{
  int A[N] = {1, 3, 7, 5};
  int B[N] = {6, 8, 4, 2};
  Matrix C = SQUARE_MARTRIX_MULTIPLY(A, B);
  printMatrix(C, n);
  free(C);
}
