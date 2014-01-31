#include <stdio.h>

extern void BUILD_MAX_HEAP(int* A, int heap_size);

void
printHeap(int* A, int heap_size)
{
  int i = 0; // number of heap array, start from 0;
  int k = 0; // number of current level. k(i+1) = 2* k(i) + 1
  while ((2*k + 1) <= heap_size) {
    for (; i < 2*k + 1; i++) {
      printf("%4d", A[i]);
    }
    printf("\n");
    k = 2*k + 1;
  }
  for (; i < heap_size; i++) {
    printf("%4d", A[i]);
  }
}

int
main(int argc, char* argv[])
{
  int A[14] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
  BUILD_MAX_HEAP(A, 14);
  printHeap(A, 14);
}
