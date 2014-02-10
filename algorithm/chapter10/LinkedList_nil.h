// Double linkedlist with nill as sentinels

template <class T>
class LinkedListItem;

template <class T>
class LinkedListNil
{
public:
  int length;
  LinkedListItem<T>* nil;

  LinkedListNil();
  ~LinkedListNil();
  LinkedListItem<T>* Search(const T& k); // linear search
  void Insert(const T& x);
  void Delete(const T& x);
  void Delete(LinkedListItem<T>* item);
};

template <class T>
class LinkedListItem
{
 private:
  T key;
  LinkedListItem<T>* prev;
  LinkedListItem<T>* next;
 public:
  LinkedListItem();
  friend class LinkedListNil<T>;
};
