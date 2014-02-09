#ifndef QUEUE
#define QUEUE
template <class T>
class Queue
{
  enum {
    uplength = 5
  };
  T* _array;
  int head;
  int tail;
  int _capacity;
 public:
  Queue(int capacity);
  Queue(int length, T* array);
  ~Queue();
  T& operator[] (const int index);
  Queue<T>& operator= (const Queue<T>& qu);
  int enqueue(const T& x);
  bool dequeue(T& x);
};
#endif
