#include <stdlib.h>
#include <string.h>
class MaxPriorityQueue {
  int* A;
  int heap_size;
public:
  MaxPriorityQueue(int* _A, int _heap_size); ///heapify array
  ~MaxPriorityQueue();
  ///Description: return the largest key;
  int HEAP_MAXIMUM();
  ///Description: Extract_Max removes and returns the element of S with the largest key;
  int HEAP_EXTRACT_MAX();
  ///Description: impove A[i] up to value key. and re-heapify
  void HEAP_INCREASE_KEY(int i, int key);
  ///Description: insert
  void MAX_HEAP_INSERT(int key);
};
