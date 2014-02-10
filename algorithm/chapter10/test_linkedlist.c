#include "LinkedList.h"
#include <cstdio>

using namespace std;

int
main(int argc, char* argv[])
{
  LinkedList<int> L;
  L.Insert(1);
  L.Insert(2);
  LinkedListItem<int>* i = L.Search(1);
  L.Delete(i);
  L.Delete(2);
}
