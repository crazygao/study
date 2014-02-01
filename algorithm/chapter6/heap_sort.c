#define EXCHANGE(x, y) ((x) = (x) + (y), (y) = (x) - (y), (x) = (x) - (y))

extern void MAX_HEAPIFY(int* A,int heap_size, int i);
extern void BUILD_MAX_HEAP(int* A, int heap_size);

#ifdef DEBUG
#include <stdio.h>
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
  printf("\n");
}
#endif

void
HEAPSORT(int* A, int heap_size)
{
  int i;
  BUILD_MAX_HEAP(A, heap_size);
#ifdef DEBUG
  printHeap(A, heap_size);
#endif
  for (i = heap_size - 1; i >= 1; i--) {
    EXCHANGE(A[0], A[i]);
    heap_size--;
    MAX_HEAPIFY(A, heap_size, 0);
#ifdef DEBUG
    printHeap(A, heap_size);
#endif
  }
}
