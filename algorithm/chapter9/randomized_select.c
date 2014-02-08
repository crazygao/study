
extern int RANDOMIZED_PARTITION(int* A, int p, int r);
int
RANDOMIZED_SELECT(int* A, int p, int r, int i)
{
  int q,k;
  if (p == r)
    return A[p];
  q = RANDOMIZED_PARTITION(A, p, r);
  k = q - p + 1;
  if (i == k) // the pivot value is the answer;
    return A[q];
  else if (i < k)
    return RANDOMIZED_SELECT(A, p, q-1, i);
  else return RANDOMIZED_SELECT(A, q+1, r, i - k);
}
