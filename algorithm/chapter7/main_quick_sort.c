#include <stdio.h>

extern void QUICKSORT(int*, int, int);

void
printArray(int* A, int size)
{
  int i;
  for (i = 0; i < size; i++) {
    printf("%4d", A[i]);
  }
  printf("\n");
}

int
main(int argc, char* argv[])
{
  int A[7] = {0, 20, 10, 78, 13, 37, 44};
  QUICKSORT(A, 0, 6);
  printf("Final Round\n");
  printArray(A, 7);
}
