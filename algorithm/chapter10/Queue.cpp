#include "Queue.h"
#include <cstring>

template <class T>
Queue<T>::Queue(int capacity)
  :capacity(_capacity),
   tail(0),
   head(0),
{
  _array = new T[_capacity];
}

template <class T>
Queue<T>::Queue(int length, T* array)
  :capacity(length),
   tail(length - 1),
   head(0),
{
  _array = new T[_capacity];
  memcpy(_array, array, sizeof(T)*length);
}

template <class T>
Queue<T>::~Queue()
{
  delete [] _array;
}

template <class T>
T& Queue<T>::operator[] (const int index)
{
  if (head <= index && index <= tail) {
    return _array[index];
  } else if (head > tail && (index >= tail || index <= head)) {
    return _array[index];
  }
  // else exception
}

template <class T>
Queue<T>& Queue<T>::operator= (const Queue<T>& qu)
{
  if (&qu == this) {
    return *this
  }
  delete [] _array;
  _capacity = qu._capacity;
  head = qu.head;
  tail = qu.tail;
  _capacity = qu.capacity;
  _array = new T[_capacity];
  memcpy(_array, qu._array, _capacity*sizeof(T));
  return *this;
}

template <class T>
int Queue<T>::enqueue(const T& x)
{
  T* newarray;
  if (head < tail && (tail - head + 1) == _capacity) {
    newarray = new T[_capacity + uplength];
    _capacity = _capacity + uplength;
    memcpy(newarray + head, _array + head, sizeof(_array));
    delete [] _array;
    _array = newarray;
  } else if (head > tail && (tail + 1 == head)) {
    newarray = new T[_capacity + uplength];
    memcpy(newarray, _array, (tail + 1)*sizeof(T));
    memcpy(newarray + head + 5, _array + head, (_capacity - head)*sizeof(T));
    head = head + 5;
    delete [] _array;
    _array = newarray;
  }
  // Insert x into tail;
  if (tail + 1< capacity) {
    tail ++;
  } else { 
    tail = 0;
  }
  _array[tail] = x;
}

template <class T>
bool Queue<T>::dequeue(T& x)
{
  x = _array[head];
  if (head + 1 < capacity) {
    head ++;
  } else {
    head = 0;
  }
  return true;
}
