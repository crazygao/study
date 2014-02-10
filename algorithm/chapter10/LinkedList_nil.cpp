#include "LinkedList_nil.h"
#define NULL 0x00000000

template <class T>
LinkedListNil<T>::LinkedListNil()
  :length(0)
{
  nil = new LinkedListItem<T>();
  nil->prev = nil;
  nil->next = nil;
}

template <class T>
LinkedListNil<T>::~LinkedListNil()
{
  int i;
  for (i = 0; i < length; i ++) {
    Delete(nil->next);
  }
  delete nil;
}

template <class T>
LinkedListItem<T>* LinkedListNil<T>::Search(const T& k)
{
  LinkedListItem<T>* x = nil->next;
  while(x != NULL && x->key != k)
    x = x->next;
  return x;
}

template <class T>
void LinkedListNil<T>::Insert(const T& x)
{
  LinkedListItem<T>* p = new LinkedListItem<T>();
  p->key = x;
  p->next = nil->next;
  nil->next->prev = p;
  nil->next = p;
  p->prev = nil;
  length ++;
}

template <class T>
void LinkedListNil<T>::Delete(LinkedListItem<T>* item)
{
  item->prev->next = item->next;
  item->next->prev = item->prev;
  delete item;
  length --;
}

template <class T>
void LinkedListNil<T>::Delete(const T& x)
{
  LinkedListItem<T>* item = Search(x);
  Delete(item);
}

template <class T>
LinkedListItem<T>::LinkedListItem()
{}

template class LinkedListItem<int>;
template class LinkedListNil<int>;
