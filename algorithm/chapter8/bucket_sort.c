#include <stdlib.h>
#ifdef DEBUG
#include <stdio.h>
#endif
struct LinkList
{
  double value;
  struct LinkList* next;
};

struct LinkListHead
{
  int length;
  struct LinkList* first;
};

void
Insert(struct LinkListHead* B, double num)
{
  int i;
  struct LinkList* p;
  struct LinkList* Num = calloc(1, sizeof(struct LinkList));
  Num->value = num;
  if (B->length == 0) {
    B->first = Num;
    B->length++;
    return;
  }
  for (i = 0, p = B->first; i <= B->length - 1; i++, p = p->next) {
    if (i == 0 && num < p->value) {
      Num->next = p;
      B->first = Num;
      B->length++;
      return;
    }
    if (num < p->next->value) {
      Num->next = p->next;
      p->next = Num;
      B->length++;
      return;
    }
    // Normal going;
  }
  if (i == B->length) {
    p->next = Num;
    B->length ++;
  }
}

void
Pop(struct LinkListHead* B, int* key, double* A)
{
  int i;
  struct LinkList* p;
  struct LinkList* freePointer;
  for (i = 0, p = B->first; i < B->length; i++, *key = *key + 1) {
    A[*key] = p->value;
    freePointer = p;
    p = p->next;
    free(freePointer);
  }
}

void
BUCKET_SORT(double* A, int length)
{
  int i, j;
  struct LinkListHead* B = (struct LinkListHead*)calloc(length, sizeof(struct LinkListHead));
  for (i = 0; i < length; i++) {
    Insert(B +((int)(length*A[i])), A[i]);
  }
#ifdef DEBUG
  struct LinkList* p;
  for (i = 0; i < length; i++) {
    printf("B[%d], length=%d:", i, B[i].length);
    for (j = 0, p = B[i].first; j < B[i].length; j++, p = p->next) {
      printf(" %3.2f", p->value);
    }
    printf("\n");
  }
#endif
  j = 0;
  for (i = 0; i < length; i++) {
    Pop(B + i, &j, A);
  }
  free(B);
}
