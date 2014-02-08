#ifndef STACK
#define STACK
template <class T>
class Stack
{
  enum {
    uplength = 5
  };
  T* _array;
  int top; // length - 1;
  int _capacity;
public:
  Stack(int capacity);
  Stack(int length, T* array);
  ~Stack();
  T& operator[] (const int index);
  Stack<T>& operator= (const Stack<T>& st);
  int push(const T& x); // return index
  bool pop(T& x);
  bool empty();
};
#endif
