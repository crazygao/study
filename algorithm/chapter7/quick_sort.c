///Declaration QuickSort: good average performance
/* Divide: Partition(rearrange) the array A[p..r] into two(possibly empty) subarrays A[p..q-1] and A[q+1..r], such that each element of A[p..q-1] <= A[q] <= A[q+1..r]. Compute the index q as part of this partitioning procedure.

Conquer: Sort the two subarraysA[p..q-1] and A[q+1..r] by recursive calls to quicksort.

Combine: Because the subarrays are already sorted, no work is needed to combine them: the entire array A[p..r] is now sorted.
*/
#ifdef DEBUG
#include <stdio.h>
void
printIt(int* A, int size)
{
  int i;
  for (i = 0; i < size; i++) {
    printf("%4d", A[i]);
  }
  printf("\n");
}
#endif


#define EXCHANGE(x, y) ((x) = (x) + (y), (y) = (x) - (y), (x) = (x) - (y))

/// 7.1-2, if all elements are the same, it will be extremely inefficient!
// isEqual is a value to try it.
int
PARTITION(int* A, int p, int r)
{
  int x = A[r]; // last index
  int i = p-1; // one index prior to the first index
  int isEqual = 1; // true, all values are true.
  int j;
  for(j = p; j <= r-1; j++)
    if (A[j] < x) {
      isEqual = 0;
      i = i+1;
      if (i != j)
	EXCHANGE(A[i], A[j]);  // move smaller values to right position
    } else if (A[j] > x) {
      isEqual = 0;
    }
  if (isEqual == 0 && i+1 != r) {
    EXCHANGE(A[i+1], A[r]);// move r to right position
    return i + 1;
  }
  return (p + r)/2;
}

void
QUICKSORT(int* A, int p, int r)
{
  int q;
  if(p < r) {
    q = PARTITION(A, p, r);
#ifdef DEBUG
    printf("QSort p=%d, q-1=%d\n", p, q-1);
#endif
    QUICKSORT(A, p, q-1);
#ifdef DEBUG
    printIt(A, 7);
    printf("QSort q+1=%d, r=%d\n", q+1, r);
#endif
    QUICKSORT(A, q+1, r);
#ifdef DEBUG
    printIt(A, 7);
#endif
  }
}
