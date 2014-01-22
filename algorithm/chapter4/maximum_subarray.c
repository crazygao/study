///Description: maximum subarray
//Solution using divide-and-conquer
/*Split A[low..high] into three parts: 
    A:A[low..mid],low <= i <= j <= mid;
    B:A[mid+1..high],mid < i<=j <= high;
    C:cross the midpoint
  A and B could be solved by FIND_MAXIMUM_SUBARRAY
  C: FIND_MAX_CROSSING_SUBARRAY, this could be split into two subarrays, A[i..mid], A[mid..j], and find the maximum of A[i, j].
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
FIND_MAX_CROSSING_SUBARRAY(int* A,int low,int mid,int high)
{
  RetValue ret;
  int left_sum = 0x80000000; //1: minimum of integer
  int sum = 0; // 2
  int i = 0;
  for(i = mid; i >= low; i--) { // 3
    sum = sum + A[i]; // 4
    if (sum > left_sum) { // 5, find the largest sum and memory the biggest one.
      left_sum = sum; // 6
      ret.max_left = i; // 7
    }
  }
  int right_sum = 0x80000000; //8: minimum of integer
  sum = 0; // 9
  int j = 0;
  for (j = mid + 1; j <= high; j++) { // 10
    sum = sum + A[j]; // 11
    if (sum > right_sum) { // 12
      right_sum = sum; // 13
      ret.max_right = j; // 14
    }
  }
  ret.sum = left_sum + right_sum;
  return ret; // 15
}

RetValue
FIND_MAXIMUM_SUBARRAY(int* A, int low, int high)
{
  RetValue ret;
  if(high == low) { // 1
    ret.max_left = low;
    ret.max_right = high;
    ret.sum = A[low];
#ifdef DEBUG
    printRet(ret);
#endif
    return ret; // 2 base case: only one element
  } else {
    int mid = (low + high) / 2; // 3
#ifdef DEBUG
    printf("FIND_MAXIMUM_SUBARRAY(low: %d, mid: %d)\n", low, mid);
#endif
    RetValue leftRet = FIND_MAXIMUM_SUBARRAY(A, low, mid); // 4
#ifdef DEBUG
    printf("FIND_MAXIMUM_SUBARRAY(mid+1: %d, high: %d)\n", mid+1, high);
#endif
    RetValue rightRet = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high); // 5
#ifdef DEBUG
    printf("FIND_MAX_CROSSING_SUBARRAY(low: %d, mid: %d, high: %d)\n", low, mid, high);
#endif
    RetValue crossRet = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high); //6
#ifdef DEBUG
    printRet(leftRet);
    printRet(rightRet);
    printRet(crossRet);
#endif
    if (leftRet.sum >= rightRet.sum && leftRet.sum >= crossRet.sum){ // 7
#ifdef DEBUG
      printf("Choose left\n");      
#endif
      return leftRet; // 8
    } else if (rightRet.sum >= leftRet.sum && rightRet.sum >= crossRet.sum){ // 9
#ifdef DEBUG
      printf("Choose right\n");
#endif
      return rightRet; // 10
    } else {
#ifdef DEBUG
      printf("Choose cross\n");
#endif
      return crossRet; // 11
    }
  }
}
