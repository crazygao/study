#ifndef _AVLNODE
#define _AVLNODE
#include "binary_search_tree.h"
typedef enum Balance { // right - left =  balance
  overleft = -2,
  left = -1,
  equal = 0,
  right = 1,
  overright = 2
} Balance;
typedef struct AVLNode
{
  BSTNode bstnode;
  Balance balance;
} AVLNode;

AVLNode* BuildAVLTree();
AVLNode* TreeInsertAVL(AVLNode** root, int key, void* memory);
void TreeBalanceAVL(AVLNode* root, AVLNode* elem, Balance bal);
void LeftRotate(AVLNode* x);
void RightRotate(AVLNode* y);
#endif
