///Description: Problem 7.4-5
// We can improve running time of quicksort by insertion sort.
// The last few recursion could be completed by insertion sort.

extern void INSERTION_SORT(int* A, int length);
extern int PARTITION(int* A, int p, int r);

void
QUICK_INSERTION_SORT(int* A, int p, int r, int k)
{
  int q;
  if (r - p > k) {
    q = PARTITION(A, p, r);
    QUICK_INSERTION_SORT(A, p, q-1, k);
    QUICK_INSERTION_SORT(A, q+1, r, k);
  } else {
    INSERTION_SORT(A + p, r - p + 1);
  }
}
