#include "binary_search_tree.h"
#include <stdio.h>

int
main(int argc, char* argv[])
{
  BSTNode* p = BuildTestTree();
  INORDER_TREE_WALK(p, printNode);
  printf("\n");
  BSTNode* k = TREE_SEARCH(p, 7);
  TREE_DELETE(p, k);
  INORDER_TREE_WALK(p, printNode);
  return 0;
}
