///Description: for each matrix, we have
// A= (A11, A12, A21, A22), B= (B11, B12, B21, B22),
// C11 = A11*B11 + A12*B21
// C12 = A11*B12 + A12*B22
// C21 = A21*B11 + A22*B21
// C22 = A21*B12 + A22*B22
// Assume n is exactly power of 2
#include "matrix.h"
#include <string.h>

Matrix
SQUARE_MATRIX_MULTIPLY_RECURSIVE(Matrix A, Matrix B, int k) {
  Matrix C = buildMatrix(k*k);// 2
  if (k == 1) { // 3
    C[0] = A[0] * B[0]; // 4
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
#ifdef DEBUG
    printf("A:\n");
    printMatrix(A, k);
    printf("A11:\n");
    printMatrix(A11, k/2);
    printf("A12:\n");
    printMatrix(A12, k/2);
    printf("A21:\n");
    printMatrix(A21, k/2);
    printf("A22:\n");
    printMatrix(A22, k/2);
#endif
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
#ifdef DEBUG
    printf("B:\n");
    printMatrix(B, k);
    printf("B11:\n");
    printMatrix(B11, k/2);
    printf("B12:\n");
    printMatrix(B12, k/2);
    printf("B21:\n");
    printMatrix(B21, k/2);
    printf("B22:\n");
    printMatrix(B22, k/2);
#endif
    // 5
    ///Calculate
    Matrix mid1 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(A11, B11, k/2);
    Matrix mid2 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(A12, B21, k/2);
    Matrix C11 = MATRIX_ADD(mid1, mid2, k/2); // 6
    free(mid1);
    free(mid2);
    mid1 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(A11, B12, k/2);
    mid2 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(A12, B22, k/2);
    Matrix C12 =  MATRIX_ADD(mid1, mid2, k/2); // 7
    free(mid1);
    free(mid2);
    mid1 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(A21, B11, k/2);
    mid2 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(A22, B21, k/2);
    Matrix C21 =  MATRIX_ADD(mid1, mid2, k/2);// 8
    free(mid1);
    free(mid2);
    mid1 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(A21, B12, k/2);
    mid2 = SQUARE_MATRIX_MULTIPLY_RECURSIVE(A22, B22, k/2);
    Matrix C22 = MATRIX_ADD(mid1, mid2, k/2); // 9
    free(mid1);
    free(mid2);
    free(A11);
    free(A12);
    free(A21);
    free(A22);
    free(B11);
    free(B12);
    free(B21);
    free(B22);
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
  return C; // 10
}

Matrix
SQUARE_MARTRIX_MULTIPLY(Matrix A, Matrix B)
{
  return SQUARE_MATRIX_MULTIPLY_RECURSIVE(A, B, n);
}
