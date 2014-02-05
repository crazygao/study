#include <stdio.h>

extern void RADIX_SORT(int* A, int lengthA, int digits);

int
main(int argc, char* argv[])
{
  int A[10] = {12, 13, 2, 3, 34, 23, 25, 32, 78, 65};
  int i;
  /*for (i = 0; i < 10; i++) {
    printf("%4d", A[i]);
  }
  printf("\n");*/
  RADIX_SORT(A, 10, 2);
  for (i = 0; i < 10; i++) {
    printf("%4d", A[i]);
  }
  printf("\n");
}
