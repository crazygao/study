///Description: Maintain min-heap property
// Input: Array A, index i.

#define LEFT(x) 2*(x)+1
#define RIGHT(x) 2*(x)+2
#define EXCHANGE(x, y) ((x) = (x) + (y), (y) = (x) - (y), (x) = (x) - (y))

void
MIN_HEAPIFY(int* A, int heap_size, int i)
{
  int l = LEFT(i);
  int r = RIGHT(i);
  int least;
  if (l < heap_size && A[l] < A[i])
    least = l;
  else
    least = i;
  if (r < heap_size && A[r] < least)
    least = r;
  if (least != i) {
    EXCHANGE(A[i], A[least]);
    MAX_HEAPIFY(A, heap_size, largest);
  }
}
