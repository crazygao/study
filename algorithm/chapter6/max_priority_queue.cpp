#include "max_priority_queue.h"
#include <stdio.h>

#define PARENT(i) (((i) + 1)/2 - 1)
#define EXCHANGE(x, y) ((x) = (x) + (y), (y) = (x) - (y), (x) = (x) - (y))

extern "C" {
  void MAX_HEAPIFY(int*, int, int);
  void BUILD_MAX_HEAP(int*, int);
};

MaxPriorityQueue::MaxPriorityQueue(int* _A, int _heap_size) {
  heap_size = _heap_size;
  A = (int*)malloc(sizeof(int)*10);
  memcpy(A, _A, sizeof(int)*10);
  BUILD_MAX_HEAP(A, heap_size);
}

MaxPriorityQueue::~MaxPriorityQueue() {
  free(A);
}

int MaxPriorityQueue::HEAP_MAXIMUM() {
  return A[0];
}

int MaxPriorityQueue::HEAP_EXTRACT_MAX() {
  int max;
  if(heap_size < 1) {
    printf("heap underflow");
    return -1;
  }
  max = A[0];
  A[0] = A[heap_size - 1];
  heap_size = heap_size - 1;
  MAX_HEAPIFY(A, heap_size, 0);
  return max;
}

void MaxPriorityQueue::HEAP_INCREASE_KEY(int i, int key) {
  if (key < A[i]) {
    printf("new key is smaller than current key");
    return;
  }
  A[i] = key;
  while(i > 0 && A[PARENT(i)] < A[i]) {
    EXCHANGE(A[i], A[PARENT(i)]);
    i = PARENT(i);
  }
}

void MaxPriorityQueue::MAX_HEAP_INSERT(int key) {
  heap_size += 1;
  A[heap_size - 1] = 0x80000000;
  HEAP_INCREASE_KEY(heap_size - 1, key);
}
