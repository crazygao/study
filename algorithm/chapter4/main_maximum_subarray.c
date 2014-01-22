#include <stdio.h>
#include "struct_retvalue.h"
extern RetValue FIND_MAXIMUM_SUBARRAY(int* A, int low, int high);

int
main(int argc, char* argv[])
{
  int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  RetValue ret = FIND_MAXIMUM_SUBARRAY(A, 0, 15);
  printf("ret.max_left: %d, ret.max_right: %d, ret.sum: %d\n", ret.max_left, ret.max_right, ret.sum);
  return 0;
}
