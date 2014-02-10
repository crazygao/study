#include "LinkedList.h"
#define NULL 0x00000000

template <class T>
LinkedList<T>::LinkedList()
  :length(0),
   head(NULL)
{}

template <class T>
LinkedList<T>::~LinkedList()
{
  int i;
  for (i = 0; i < length; i ++) {
    Delete(head);
  }
}

template <class T>
LinkedListItem<T>* LinkedList<T>::Search(const T& k)
{
  LinkedListItem<T>* x = head;
  while(x != NULL && x->key != k)
    x = x->next;
  return x;
}

template <class T>
void LinkedList<T>::Insert(const T& x)
{
  LinkedListItem<T>* p = new LinkedListItem<T>();
  p->key = x;
  p->next = head;
  if (head != NULL)
    head->prev = p;
  head = p;
  p->prev = NULL;
  length ++;
}

template <class T>
void LinkedList<T>::Delete(LinkedListItem<T>* item)
{
  if (item->prev != NULL)
    item->prev->next = item->next;
  else
    head = item->next;
  if (item->next != NULL)
    item->next->prev = item->prev;
  delete item;
  length --;
}

template <class T>
void LinkedList<T>::Delete(const T& x)
{
  LinkedListItem<T>* item = Search(x);
  Delete(item);
}

template <class T>
LinkedListItem<T>::LinkedListItem()
{}

template class LinkedListItem<int>;
template class LinkedList<int>;
