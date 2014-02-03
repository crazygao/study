#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LENGTH 1000

extern void QUICK_INSERTION_SORT(int* A, int p, int r, int k);

void
GenerateArray(int* A, int length) {
  int i;
  srand(time(NULL));
  for (i = 0; i < length; i++) {
    A[i] = rand() % 1000;
  }
}

void printArray(int* A, int length) {
  int i, j;
  for (i = 0; i*10 + 9 < length; i++) {
    for (j = 0; j < 10; j++) {
      printf("%4d", A[10*i + j]);
    }
    printf("\n");
  }
  for (j = 10*i; j < length; j++) {
    printf("%4d", A[j]);
  }
  printf("\n");
}

int
main(int argc, char* argv) {
  clock_t t;
  int* A = (int*)malloc(sizeof(int)*LENGTH);
  GenerateArray(A, LENGTH);
  t = clock();
  QUICK_INSERTION_SORT(A, 0, LENGTH-1, 1);
  t = clock() - t;
  printArray(A, LENGTH);
  printf("Take %d clicks( %f secs )\n", t, ((float)t)/CLOCKS_PER_SEC);
}
