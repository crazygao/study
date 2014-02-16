
int
h(int key, int i) { // hash function.
  return i;
}

int
HASH_INSERT(int* T, int m, int k) // m is length of T
{
  int i = 0;
  int j;
  do {
    j = h(k, i); // 
    if (T[j] == NULL) {
      T[j] = k;
      return j;
    } else
      i = i + 1;
  } while(i == m);
}
