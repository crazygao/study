
#include <stdio.h>
extern void COUNTING_SORT(int* A, int lengthA, int* B,int k);

int
main(int argc, char* argv[])
{
  int A[11] = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
  int B[11] = {0};
  int i;
  COUNTING_SORT(A, 11, B, 6);
  for (i = 0; i < 11; i++) {
    printf("%4d", B[i]);
  }
  printf("\n");
}
