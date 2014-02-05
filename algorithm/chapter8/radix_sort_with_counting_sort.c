///Description: Radix sort. sort with counting sort on every digit.

#include <stdlib.h>
#include <string.h>
#ifdef DEBUG
#include <stdio.h>
void printArray(int* A, int length)
{
  int i;
  for (i = 0; i < length; i ++) {
    printf("%4d", A[i]);
  }
  printf("\n");
}
#endif
int
GetDigit(int num, int digit)
{
  if (digit == 1) {
    return num % 10;
  }
  return (num/(10^(digit-1)))%10;
}

void
COUNTING_SORT_DIGIT(int* A, int lengthA, int* B, int digit)// k = 9 because 0..9
{
  int C[10] = {0};
  int i, j;
  int tempDigit;
  for (i = 0; i <= 9; i++) {
    C[i] = 0;
  }
  for (j = 0; j < lengthA; j++) {
    tempDigit = GetDigit(A[j], digit);
    C[tempDigit] = C[tempDigit] + 1;
#ifdef DEBUG
    printf("tempDigit: %d, C[%d]: %d\n", tempDigit, tempDigit, C[tempDigit]);
#endif
  }
  for (i = 1; i <= 9; i++) {
    C[i] = C[i] + C[i-1];
  }
#ifdef DEBUG
  printf("Array C in digit %d:\n", digit);
  printArray(C, 10);
#endif
  for (j = lengthA - 1; j >= 0; j--) {
    tempDigit = GetDigit(A[j], digit);
    B[C[tempDigit] - 1] = A[j];
    C[tempDigit] = C[tempDigit] - 1;
#ifdef DEBUG
    printf("j = %d, tempDigit = %d, C[tempDigit] - 1 = %d\n", j, tempDigit, C[tempDigit]);
    printArray(B, lengthA);
#endif
  }
}

void
RADIX_SORT(int* A, int lengthA, int digits)
{
  int i;
  int* B = (int*)malloc(sizeof(int)*lengthA);
  for (i = 1; i <= digits; i++) {
    COUNTING_SORT_DIGIT(A, lengthA, B, i);
    memcpy(A, B, lengthA*sizeof(int));
#ifdef DEBUG
    printf("Array A in digit %d:\n", i);
    printArray(A, lengthA);
#endif
  }
}
