///Description: Recursion in MAX_HEAPIFY may cause inefficient code.

#define LEFT(x) 2*(x)+1
#define RIGHT(x) 2*(x)+2
#define EXCHANGE(x, y) ((x) = (x) + (y), (y) = (x) - (y), (x) = (x) - (y))

void
MAX_HEAPIFY(int* A, int heap_size, int i)
{
  int l, r, largest;
  do {
    l = LEFT(i);
    r = RIGHT(i);
    if (l < heap_size && A[l] > A[i]) // l and r should less than heap_size, not less or equal.
      largest = l;
    else
      largest = i;
    if (r < heap_size && A[r] > A[largest])
      largest = r;
    if (largest != i) {
      EXCHANGE(A[i], A[largest]);
      l = LEFT(largest);
      r = RIGHT(largest);
      i = largest;
    } else {
      break;
    }
  } while (1);
}

/*
for(sta1;sta2;sta3)
{
   sta4;
}

1.first time sta1;
2.sta2; // true and loop; false and jump out of loop
3.sta4;
4,sta3;
5,back to 2.
*/
