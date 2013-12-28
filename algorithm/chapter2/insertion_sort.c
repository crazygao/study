///Input: a sequence of numbers a0 a1 .. an-1
///Output: a permutation a0' a1' .. an-1' of the input sequence such that
// a0' <= a1' <= .. <= an-1'

///Description: it is an efficient algorithm fo sorting a small amount of
// elements. we remove one number at a time from the array and insert it
// into the correct position. To find the correct position for a card, we
// COMPARE it with each of the numbers already in order, from right to left.

#include "insertion_sort_2_1_2.c" // BIGGER and smaller

void
INSERTION_SORT(int* A, int length) {
  int i, j, key;
  for (j = 1; j < length; j++) { //1
    key = A[j]; //2
    // Insert A[j] into the sorted sequence A[0 .. j-1]. 3
    i = j - 1; // 4
    while(i >= 0 && SMALLER(key, A[i])) { // 5 Exercise2.1.2: Change SMALLER to BIGGER
      A[i+1] = A[i]; //6
      i = i - 1; //7
    }
    A[i+1] = key;//8
  }
}
