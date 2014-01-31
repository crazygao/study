#include <stdio.h>
extern void MAX_HEAPIFY(int* ,int , int );

int
main(int argc, char* argv[])
{
  int A[14] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
  MAX_HEAPIFY(A, 14, 2);
  printf("%d", A[0]);
}
