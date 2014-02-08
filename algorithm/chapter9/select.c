#include <stdlib.h>

#define EXCHANGE(x, y) ((x) = (x) + (y), (y) = (x) - (y), (x) = (x) - (y))
extern void
INSERTION_SORT(int* A, int length);

int
PARTITION(int* A, int p, int r, int x)
{
  int i = p-1; // one index prior to the first index
  int isEqual = 1; // true, all values are true.
  int j;
  for(j = p; j <= r-1; j++)
    if (A[j] < x) {
      isEqual = 0;
      i = i+1;
      if (i != j)
	EXCHANGE(A[i], A[j]);  // move smaller values to right position
    } else if (A[j] > x) {
      isEqual = 0;
    } else {
      if (A[j] != A[r]) {
	EXCHANGE(A[j], A[r]);
	j--;
      }
    }
  if (isEqual == 0 && i != r) {
    EXCHANGE(A[i+1], A[r]);// move r to right position
    return i + 1;
  }
  return (p + r)/2;
}

int
SELECT(int* A, int length, int i) {
  int j, Blength;
  int* B;
  int x;
  int k;
  if (length == 1) {
    return A[0];
  }
  for (i = 0; i + 5 < length; i += 5) {
    INSERTION_SORT(A + i, 5);
  }
  if (length % 5 != 0) {
    i = i - 5;
    INSERTION_SORT(A + i, length - i);// Sort every 5 element
    Blength = length % 5 + 1;
  } else {
    Blength = length % 5;
  }
  B = (int*)calloc(Blength, sizeof(int));  
  x = SELECT(B, Blength, Blength/2);
  k = PARTITION(A, 0, length, x) + 1;
  if (k == i) {
    return x;
  } else if (i < k) {
    return SELECT(A, k, i);
  } else {
    return SELECT(A + k, length - k, i - k);
  }
}
