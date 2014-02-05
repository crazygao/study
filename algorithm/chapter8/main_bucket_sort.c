#include <stdio.h>

extern void BUCKET_SORT(double* A, int length);

int
main(int argc, char* argv[])
{
  double A[10] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
  int i;
  BUCKET_SORT(A, 10);
  for (i = 0; i < 10; i++) {
    printf(" %3.2f", A[i]);
  }
  printf("\n");
}
