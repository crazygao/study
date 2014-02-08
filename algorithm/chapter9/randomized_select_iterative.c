
extern int RANDOMIZED_PARTITION(int* A, int p, int r);

int
RANDOMIZED_SELECT(int* A, int p, int r, int i)
{
  int q, k;
  do {
    if (p == r)
      return A[p];
    q = RANDOMIZED_PARTITION(A, p, r);
    k = q - p + 1;
    if (i == k) {
      break;
    }
    if (i < k) {
      r = q - 1;
    } else {
      p = q + 1;
      i = i - k;
    }
  } while (1);
  return A[q];
}
