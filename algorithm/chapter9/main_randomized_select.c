#include <stdio.h>

extern int
RANDOMIZED_SELECT(int* A, int p, int r, int i);

int
main()
{
  int A[12] = {2,4,21,123,412,21, 45,62, 36,78,904, 45};
  int i;
  printf("A: ");
  for (i = 0; i < 12; i++)
    printf("%4d", A[i]);
  printf("\n");
  printf("the 4th number is %d\n", RANDOMIZED_SELECT(A, 0, 11, 4));
}
