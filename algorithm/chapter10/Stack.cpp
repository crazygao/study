#include "Stack.h"
#include <cstdlib>
#include <cstring>

using namespace std;
template <class T>
Stack<T>::Stack(int capacity)
  :_capacity(capacity),
   top(0)
{
  _array = new T[_capacity];
}

template <class T>
Stack<T>::Stack(int length, T* array)
  :_capacity(length),
   top(length - 1)
{
  _array = (T*)malloc(sizeof(T)*length);
  memcpy(_array, array, length*sizeof(T));
}

template <class T>
Stack<T>::~Stack()
{
  delete [] _array;
}

template <class T>
T& Stack<T>::operator[] (const int index)
{
  if (index <= top) {
    return _array[index];
  }
}

template <class T>
int Stack<T>::push(const T& x)
{
  if (top + 1 >= _capacity) {
    _array = (T*)realloc((void*)_array, (_capacity + uplength)*sizeof(T));
    _capacity = _capacity + uplength;
  }
  top++;
  _array[top] = x;
  return top;
}

template <class T>
bool Stack<T>::pop(T& x)
{
  if (!empty()) {
    top = top - 1;
    x = _array[top + 1];
    return true;
  }
  return false;
}

template <class T>
bool Stack<T>::empty()
{
  return top == 0;
}

template <class T>
Stack<T>& Stack<T>::operator= (const Stack<T>& st)
{
  if (this == &st) {
    return *this;
  }

  delete [] _array;

  _capacity = st._capacity;
  top = st.top;
  _array = (T*)malloc(sizeof(T)*_capacity);
  memcpy(_array, st._array, _capacity*sizeof(T));
  return *this;
}

// Instantiate Stack for the support template type
template class Stack<int>;
