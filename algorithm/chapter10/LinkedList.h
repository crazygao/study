// Double linkedlist
template <class T>
class LinkedListItem;

template <class T>
class LinkedList
{
 public:
  int length;
  LinkedListItem<T>* head;

  LinkedList();
  ~LinkedList();
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
  friend class LinkedList<T>;
};
