///Description: counting sort, sort on whole element
#include <stdlib.h>
void
COUNTING_SORT(int* A, int lengthA, int* B,int k) {
  int* C = (int*)malloc(sizeof(int)*(k+1));
  int i, j;
  for (i = 0; i <= k; i++) {
    C[i] = 0;
  }
  for (j = 0; j < lengthA; j++) {
    C[A[j]] = C[A[j]] + 1;
  }
  // C[i] now contains the number of elements equal to i.
  for (i = 1; i <=k; i++)
    C[i] = C[i] + C[i - 1];
  // C[i] now contains the number of elements less than or equal to i.
  for (j = lengthA - 1; j >= 0; j--) {
    B[C[A[j]] - 1] = A[j]; // C[A[j]] is counting  C[A[j]]-1 is index
    C[A[j]] = C[A[j]] - 1;
  }
  free(C);
}
