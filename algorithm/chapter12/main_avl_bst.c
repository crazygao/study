#include "AVLNode.h"
#include <stdio.h>

int
main(int argc, char* argv[])
{
  AVLNode* p = BuildAVLTree();
  INORDER_TREE_WALK(&(p->bstnode), printNode);
  printf("\n");
  return 0;
}
