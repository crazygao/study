///Description: maximum subarray with complexity of theta(n)
// Solution: using methods like insert sort, but this time we need to make partB to end in a constant time!! So we need the help of spare storage. And this time we cannot use a recursive function.

/* Basic: To make max_sub(A[1..high]) -> max_sub(A[1..high+1])
   max_sub(A[1..high+1]) = max_sub(A[1..high]) or max_sub(length(A[i], A[high+1])
   if we memory the max_sub(length(A[i], A[high])), then max_sub(max_sub(length(A[i], A[high])) + A[high+1], and A[high+1]) will be the next value. that is another iteration
*/

#include "struct_retvalue.h"

RetValue
FIND_MAXIMUM_SUBARRAY(int* A, int low, int high)
{
  int j;
  RetValue max_sub_0_high = {low, low, A[low]}; // Save max_sub(A[0..high]),start from A[low]

  RetValue max_sub_i_high = {low, low, A[low]}; // Save max_sub(length(A[i], A[high]), 0 <= i <= high
  for (j = low + 1; j <= high; j++) { // push forward the array
    if (max_sub_i_high.sum + A[j] >= A[j]) { // find max_sub(length(A[i], A[high+1]))
      max_sub_i_high.max_right = j;
      max_sub_i_high.sum = max_sub_i_high.sum + A[j];
    } else {
      max_sub_i_high.max_left = j;
      max_sub_i_high.max_right = j;
      max_sub_i_high.sum = A[j];
    }
    if (max_sub_i_high.sum > max_sub_0_high.sum) { // Compare max_sub(A[1..high]) and max_sub(length(A[i], A[high+1])
      max_sub_0_high.sum = max_sub_i_high.sum;
      max_sub_0_high.max_right = max_sub_i_high.max_right;
      max_sub_0_high.max_left = max_sub_i_high.max_left;
    }
  }
  return max_sub_0_high;
}

