#include <stdio.h>
extern void INSERTION_SORT(int*, int);
/// Description: exercise 2.1-1

int
main() {
  int length = 6;
  int i;
  int A[6] = {31, 41, 59, 26, 41, 58};
  INSERTION_SORT(A, length);
  for (i = 0; i < length; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}
