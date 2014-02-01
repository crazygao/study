#include "max_priority_queue.h"
#include <stdio.h>

int
main(int argc, char* argv[])
{
  int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  MaxPriorityQueue queue(A, 10);
  int a = queue.HEAP_EXTRACT_MAX();
  a = queue.HEAP_MAXIMUM();
  queue.HEAP_INCREASE_KEY(4, 11);
  queue.MAX_HEAP_INSERT(12);
}
