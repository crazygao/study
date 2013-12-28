/// Description: Merge Sort
// Divide: Divide the n-element sequences to be sorted into two subsequences of n/2 elements each
// Conquer: Sort the two subsequences recursively using Merge Sort.
// Combine: Merge the two sorted wubsequences to produce the sorted answer

// Definition: A is an integer array, and p<=q<r, it assumes that
// A[p..q] and A[q+1 .. r] are in sorted order. It MERGES them to form a single
// sorted subarray that replaces the current subarray A[p .. r];

// Time: Merge procedure takes time theta(n), 

#include <stdlib.h>
#ifdef DEBUG
#include <stdio.h>
#endif
void
MERGE(int* A, int p, int q, int r) {
  int n1 = q - p + 1; //1: Numbers of L array
  int n2 = r - q; //2 : Numbers of R array
  int i, j, k;
  int* L = (int*)malloc(sizeof(int) * (n1 + 1)); //3
  int* R = (int*)malloc(sizeof(int) * (n2 + 1)); //3
  // L[0 .. n1 - 1] = A[p .. q]
  for (i = 0; i < n1; i++) // 4
    L[i] = A[p + i]; // 5
  // R[0 .. n2 - 1] = A[q+1 .. r]
  for (j = 0;  j < n2; j++) //6
    R[j] = A[q + 1 + j]; //7: Second sequence starts from q + 1;
  // Twist, sentinel card, this is the max card in the L R pile.
  L[n1] = 0x7fffffff; //8
  R[n2] = 0x7fffffff; //9

  // Here are merge procedure
  i = 0; //10
  j = 0; //11
  for (k = p; k <= r; k++) //12
    if (L[i] <= R[j]) //13
      A[k] = L[i++]; // 14, 15
    else // 16
      A[k] = R[j++]; // 16, 17
  free(L);
  free(R);
}

// Definition: this sorts the elements in the subarray A[p .. r] if p >= r,
// the subarray has at most one element and is therefore already sorted.
// Otherwise, the divide step simply computes an index q that partitions
// A[p .. r] into two subarrays: A[p .. q], containing n/2 elements, and A[q + 1 .. r]
// containing n/2 elements.
void MERGE_SORT(int* A, int p, int r) {
  int q;
  int i;
  if (p < r) { // 1
    q = (p+r)/2; // 2
#ifdef DEBUG
    printf("MergeSort A, p = %d, q = %d\n", p, q);
#endif
    MERGE_SORT(A, p, q); // 3
#ifdef DEBUG
    printf("MergeSort A, q + 1 = %d, r = %d\n", q+1, r);
#endif
    MERGE_SORT(A, q + 1, r); // 4
#ifdef DEBUG
    printf("Merge A, p = %d, q = %d, r = %d\n",p, q, r);
#endif
    MERGE(A, p, q, r);
#ifdef DEBUG
    printf("Current A[p(%d)..r(%d)] is ", p, r);
    for (i = p; i <= r; i++)
      printf("%d ", A[i]);
    printf("\n");
#endif
  }
}
