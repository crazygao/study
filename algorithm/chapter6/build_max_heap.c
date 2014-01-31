///Description: use the MAX_HEAPIFY in a bottom-up manner to convert an array.
// A[1..n-1], where n = A.length into a max_heap, By Exercise 6.1-7, the
// elements in subarray A[(low(n/2))..n-1] are leaves of the tree, and so each is an 1-element heap to begin with. The BUILD_MAX_HEAP goes through the remaining nodes of the tree and runs MAX_HEAPIFY on each one
extern void MAX_HEAPIFY(int* A, int heap_size, int i);

void
BUILD_MAX_HEAP(int* A, int heap_size)
{
  int i;
  for (i = heap_size/2 - 1; i >= 0; i--)
    MAX_HEAPIFY(A, heap_size, i);
}

