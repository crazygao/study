// Exercise 2.1-3
///Input: A sequence of n numbers A = <a1, a2, ... , an> and a value v
///Output: An index i such that v = A[i] or the speial value NIL if v does not apear in A.

///Description: Get out one element from A one by one, and compare it with v.

int
LINEAR_SEARCH(int* A, int length, int v) { //1
  int i;
  for (i = 0; i < length; i++) //2
    if (A[i] == v) //3
      return i; //4
  return -1; //5 NIL
}
