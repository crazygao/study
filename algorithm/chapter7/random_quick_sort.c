///Declaration: RANDOMIZED_QUICKSORT
/* In engineering ,we cannot expect that all permutations of the input numbers are equally likely. As we can see in Section 5.3, we sometimes add randomization to an algorithm in order to obtain good expected performance over all inputs.
 */
#include <time.h>
#include <stdlib.h>

#define RANDOM(a, b) (rand()%(b-a+1) + a) //randomize between [a..b]
#define EXCHANGE(x, y) ((x) = (x) + (y), (y) = (x) - (y), (x) = (x) - (y))

int
PARTITION(int* A, int p, int r)
{
  int x = A[r]; // last index
  int i = p-1; // one index prior to the first index
  int j;
  for(j = p; j <= r-1; j++)
    if (A[j] <= x) {
      i = i+1;
      if (i != j)
	EXCHANGE(A[i], A[j]);  // move smaller values to right position
    }
  if (i+1 != r)
    EXCHANGE(A[i+1], A[r]);// move r to right position
  return i+1;
}

int
RANDOMIZED_PARTITION(int* A, int p, int r)
{
  int i = RANDOM(p, r);
  if (r != i)
    EXCHANGE(A[r], A[i]);
  return PARTITION(A, p, r);
}

void
RANDOMIZED_QUICKSORT(int* A, int p, int r)
{
  int q;
  if (p < r) {
    q = RANDOMIZED_PARTITION(A, p, r);
    RANDOMIZED_QUICKSORT(A, p, q-1);
    RANDOMIZED_QUICKSORT(A, q+1, r);
  }
}

void
QUICKSORT(int* A, int p, int r) {
  srand(time(NULL));
  RANDOMIZED_QUICKSORT(A, p, r);
}
