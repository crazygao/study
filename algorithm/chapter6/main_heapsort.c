#include <stdio.h>

extern void HEAPSORT(int* A, int heap_size);

int
main(int argc, char* argv[])
{
  int A[14] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
  HEAPSORT(A, 14);
  printf("%d", A[0]);
}
