///Description: maximum subarray with complexity of theta(n*n)
// Solution: using methods like insert sort
/*the maximum subarray in A[low, high] could be split into
  A: the maximum subarray in A[low, high-1],
  B: the maximum subarray of A[high] to A[1..high-1],
  A is the iteration of FIND_MAXIMUM_SUBARRAY
  B is the FIND_CROSS_SUBARRAY. it sums from A[high], and find the largest A[i..high], and memory the i
*/

#include "struct_retvalue.h"
#ifdef DEBUG
#include <stdio.h>
void
printRet(RetValue ret)
{
  printf("ret.max_left: %d, ret.max_right: %d, ret.sum: %d\n", ret.max_left, ret.max_right, ret.sum);
}
#endif

RetValue
FIND_CROSS_SUBARRAY(int* A, int high)
{
  RetValue ret;
  ret.sum = 0x80000000;
  int sum = A[high]; // Start from A[high]
  int i = 0;
  for (i = high - 1; i >= 0; i--) {
    sum = sum + A[i];
    if (sum > ret.sum) {// memory the biggest.
      ret.sum = sum;
      ret.max_left = i;
    }
  }
  ret.max_right = high;
  return ret;
}

RetValue
FIND_MAXIMUM_SUBARRAY(int* A, int low, int high)
{
  RetValue ret;
  if (high == low) {
    ret.max_left = low;
    ret.max_right = high;
    ret.sum = A[low];
#ifdef DEBUG
    printRet(ret);
#endif
    return ret;
  } else {
#ifdef DEBUG
    printf("FIND_MAXIMUM_SUBARRAY(low: %d, high-1: %d)\n", low, high-1);
#endif
    RetValue partA = FIND_MAXIMUM_SUBARRAY(A, low, high - 1);
#ifdef DEBUG
    printf("FIND_CROSS_SUBARRAY(high: %d)\n", high);
#endif
    RetValue partB = FIND_CROSS_SUBARRAY(A, high);
#ifdef DEBUG
    printf("partA ");printRet(partA);
    printf("partB ");printRet(partB);
#endif
    if (partA.sum >= partB.sum) {
#ifdef DEBUG
      printf("Choose PartA\n");
#endif
      return partA;
    }
    else {
#ifdef DEBUG
      printf("Choose PartB\n");
#endif
      return partB;
    }
  }
}
