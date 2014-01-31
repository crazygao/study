///Description: Maintain max-heap property
// Input: Array A, index i.
// Because C array start index from 0, so that left and right should make some change.
#define LEFT(x) 2*(x)+1
#define RIGHT(x) 2*(x)+2
#define EXCHANGE(x, y) ((x) = (x) + (y), (y) = (x) - (y), (x) = (x) - (y))


void
MAX_HEAPIFY(int* A,int heap_size, int i)
{
  int l = LEFT(i);
  int r = RIGHT(i);
  int largest;
  if (l < heap_size && A[l] > A[i]) // l and r should less than heap_size, not less or equal.
    largest = l;
  else
    largest = i;
  if (r < heap_size && A[r] > A[largest])
    largest = r;
  if (largest != i) {
    EXCHANGE(A[i], A[largest]);
    MAX_HEAPIFY(A, heap_size, largest);
  }
}
