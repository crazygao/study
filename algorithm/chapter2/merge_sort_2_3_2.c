#include <stdlib.h>
#ifdef DEBUG
#include <stdio.h>
#endif
void
MERGE(int* A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int i, j, k;
  int* L = (int*)malloc(sizeof(int) * (n1));
  int* R = (int*)malloc(sizeof(int) * (n2));
  for (i = 0; i < n1; i++)
    L[i] = A[p + i];
  for (j = 0; j < n2; j++)
    R[j] = A[q + 1 + j];

  i = 0, j = 0;
  for (k = p; (i < n1)&&(j < n2); k++)
    if (L[i] <= R[j])
      A[k] = L[i++];
    else
      A[k] = R[j++];
  for (; i < n1;)
    A[k++] = L[i++];
  for (; j < n2;)
    A[k++] = R[j++];
  free(L);
  free(R);
}

void MERGE_SORT(int* A, int p, int r) {
  int q, i;
  if (p < r) {
    q = (p + r) / 2;
#ifdef DEBUG
    printf("MergeSort A, p = %d, q = %d\n", p, q);
#endif
    MERGE_SORT(A, p, q);
#ifdef DEBUG
    printf("MergeSort A, q + 1 = %d, r = %d\n", q+1, r);
#endif
    MERGE_SORT(A, q+1, r);
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
