#include <stdio.h>
extern void MERGE_SORT(int* , int , int );

int
main() {
  int A[8] = {3, 41, 52, 26, 38, 57, 9, 49};
  MERGE_SORT(A, 0, 7);
  printf("%d %d, %d, %d, %d", A[0], A[1], A[2], A[3], A[4]);
}
