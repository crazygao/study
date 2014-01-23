///Description:
// S1 = B12 - B22
// S2 = A11 + A12
// S3 = A21 + A22
// S4 = B21 - B11
// S5 = A11 + A22
// S6 = B11 + B22
// S7 = A12 - A22
// S8 = B21 + B22
// S9 = A11 - A21
// S10 = B11 + B12

// P1 = A11*S1 = A11*B12-A11*B22
// P2 = S2*B22 = A11*B22 + A12*B22
// P3 = S3*B11 = A21*B11 + A22*B11
// P4 = A22*S4 = A22*B21 - A22*B11
// P5 = S5*S6 = A11*B11 + A11*B22 + A22*B11 + A22*B22
// P6 = S7*S8 = A12*B21 + A12*B22 - A22*B21 - A22*B22
// P7 = S9*S10 = A11*B11 + A11*B12 - A21*B11 - A21*B12

// C11 = P5 + P4 - P2 + P6
// C12 = P1 + P2
// C21 = P3 + P4
// C22 = P5 + P1 - P3 - P7

#include "matrix.h"
#include <string.h>

Matrix
SQUARE_MATRIX_MULTIPLY_RECURSIVE(Matrix A, Matrix B, int k) {
  Matrix C = buildMatrix(k*k);
  if (k == 1) {
    C[0] = A[0] * B[0];
  } else {
        int i; // for initialization
    /// Initialize of A*
    Matrix A11 = buildMatrix(k*k/4);
    for (i = 0; i < k/2; i++)
      memcpy(A11 + (k/2*i), A + (k*i), sizeof(int)*k/2);
    Matrix A12 = buildMatrix(k*k/4);
    for (i = 0; i < k/2; i++)
      memcpy(A12 + (k/2*i), A + (k*i) + k/2, sizeof(int)*k/2);
    Matrix A21 = buildMatrix(k*k/4);
    for (i = k/2; i < k; i++)
      memcpy(A21 + (k/2*(i - k/2)), A + (k*i), sizeof(int)*k/2);
    Matrix A22 = buildMatrix(k*k/4);
    for (i = k/2; i < k; i++)
      memcpy(A22 + (k/2*(i - k/2)), A + (k*i) + k/2, sizeof(int)*k/2);

    ///Initialization of B*
    Matrix B11 = buildMatrix(k*k/4);
    for (i = 0; i < k/2; i++)
      memcpy(B11 + (k/2*i), B + (k*i), sizeof(int)*k/2);
    Matrix B12 = buildMatrix(k*k/4);
    for (i = 0; i < k/2; i++)
      memcpy(B12 + (k/2*i), B + (k*i) + k/2, sizeof(int)*k/2);
    Matrix B21 = buildMatrix(k*k/4);
    for (i = k/2; i < k; i++)
      memcpy(B21 + (k/2*(i - k/2)), B + (k*i), sizeof(int)*k/2);
    Matrix B22 = buildMatrix(k*k/4);
    for (i = k/2; i < k; i++)
      memcpy(B22 + (k/2*(i - k/2)), B + (k*i) + k/2, sizeof(int)*k/2);

    /// Calculation of S*
    Matrix S1 = MATRIX_SUBSTRACT(B12, B22, k/2);
    Matrix S2 = MATRIX_ADD(A11, A12, k/2);
    Matrix S3 = MATRIX_ADD(A21, A22, k/2);
    Matrix S4 = MATRIX_SUBSTRACT(B21, B11, k/2);
    Matrix S5 = MATRIX_ADD(A11, A22, k/2);
    Matrix S6 = MATRIX_ADD(B11, B22, k/2);
    Matrix S7 = MATRIX_SUBSTRACT(A12, A22, k/2);
    Matrix S8 = MATRIX_ADD(B21, B22, k/2);
    Matrix S9 = MATRIX_SUBSTRACT(A11, A21, k/2);
    Matrix S10 = MATRIX_ADD(B11, B12, k/2);

    Matrix P1 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(A11, S1, k/2);
    Matrix P2 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(S2, B22, k/2);
    Matrix P3 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(S3, B11, k/2);
    Matrix P4 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(A22, S4, k/2);
    Matrix P5 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(S5, S6, k/2);
    Matrix P6 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(S7, S8, k/2);
    Matrix P7 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(S9, S10, k/2);

    free(A11);
    free(A12);
    free(A21);
    free(A22);
    free(B11);
    free(B12);
    free(B21);
    free(B22);

    free(S1);
    free(S2);
    free(S3);
    free(S4);
    free(S5);
    free(S6);
    free(S7);
    free(S8);
    free(S9);
    free(S10);

    Matrix mid1 = MATRIX_ADD(P5, P4, k/2);
    Matrix mid2 = MATRIX_SUBSTRACT(mid1, P2, k/2);
    Matrix C11 = MATRIX_ADD(mid2, P6, k/2);
    free(mid1);
    free(mid2);

    Matrix C12 = MATRIX_ADD(P1, P2, k/2);
    Matrix C21 = MATRIX_ADD(P3, P4, k/2);

    mid1 = MATRIX_ADD(P5, P1, k/2);
    mid2 = MATRIX_SUBSTRACT(mid1, P3, k/2);
    Matrix C22 = MATRIX_SUBSTRACT(mid2, P7, k/2);
    free(mid1);
    free(mid2);

    for (i = 0; i < k/2; i++) {
      memcpy(C + i*k, C11 + i * k/2, sizeof(int)*k/2);
      memcpy(C + i*k + k/2, C12 + i * k/2, sizeof(int)*k/2);
      memcpy(C + (i+k/2)*k, C21 + i*k/2, sizeof(int)*k/2);
      memcpy(C + (i+k/2)*k + k/2, C22 + i*k/2, sizeof(int)*k/2);
    }
    free(C11);
    free(C12);
    free(C21);
    free(C22);
  }
  return C;
}

Matrix
SQUARE_MARTRIX_MULTIPLY(Matrix A, Matrix B)
{
  return SQUARE_MATRIX_MULTIPLY_RECURSIVE(A, B, n);
}
