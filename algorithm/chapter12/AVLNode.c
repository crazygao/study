#include "AVLNode.h"
#include <stdio.h>
#include <stdlib.h>

AVLNode*
BuildAVLTree()
{
  AVLNode* root;
  root = NULL;
  TreeInsertAVL(&root, 1, NULL);
  TreeInsertAVL(&root, 2, NULL);
  TreeInsertAVL(&root, 3, NULL);
  TreeInsertAVL(&root, 4, NULL);
  TreeInsertAVL(&root, 5, NULL);
  TreeInsertAVL(&root, 6, NULL);
  TreeInsertAVL(&root, 7, NULL);
  TreeInsertAVL(&root, 8, NULL);
  return root;
}

AVLNode*
TreeInsertAVL(AVLNode** root, int key, void* memory)
{
  AVLNode* x;
  if (memory != NULL) {
    x = (AVLNode*)memory;
  } else {
    x = (AVLNode*)malloc(sizeof(AVLNode));
  }
  if (*root == NULL) {
    *root = x;
  }
  TreeInsert(&((*root)->bstnode), key, (void*)x);
  // from x, manage x's balance.
  x->balance = equal;
  TreeBalanceAVL(*root, x, x->balance);
  return x;
}

void TreeBalanceAVL(AVLNode* root, AVLNode* elem, Balance bal)
{
  // elem itself is balanced, we check their father.
  BSTNode* p1b = (elem->bstnode).parent;
  if (p1b == NULL) return;
  AVLNode* p1 = (AVLNode*)(elem->bstnode).parent;
  AVLNode* temp;
  if (p1b->left == &elem->bstnode) {
    p1->balance --;
    if (p1->balance == left)
      TreeBalanceAVL(root, p1, left);
    else if (p1->balance == overleft) {
      // rotate
      if (bal == left) {
	RightRotate(p1);
	elem->balance = equal;
	p1->balance = equal;
      } else if (bal == right) {
	temp = (AVLNode*)((elem->bstnode).right);
	if (temp->balance == left) {
	  p1->balance = equal;
	  elem->balance = left;
	} else { // always right
	  p1->balance = left;
	  elem->balance = equal;
	}
	temp->balance = equal;
	LeftRotate(elem);
	RightRotate(p1);
      }
    }
  } else {
    p1->balance ++;
    if (p1->balance == right)
      TreeBalanceAVL(root, p1, right);
    else if (p1->balance == overright) {
      // rotate;
      if (bal == right) {
	LeftRotate(p1);
	elem->balance = equal;
	p1->balance = equal;
      } else if (bal == left) {
	temp = (AVLNode*)((elem->bstnode).left);
	if (temp->balance == left) {
	  p1->balance = equal;
	  elem->balance = right;
	} else {
	  p1->balance = right;
	  elem->balance = equal;
	}
	temp->balance = equal;
	RightRotate(elem);
	LeftRotate(p1);
      }
    }
  }
}

void LeftRotate(AVLNode* x)
{
  AVLNode* y = (AVLNode*)((x->bstnode).right); // covert a bstnode back to AVLNode.
  //  AVLNode* A = (AVLNode*)((x->bstnode).left); // A & C is not used
  AVLNode* B = (AVLNode*)((x->bstnode).right->left);
  //  AVLNode* C = (AVLNode*)((x->bstnode).right->right);

  // transfer of parent
  y->bstnode.parent = x->bstnode.parent;
  x->bstnode.parent = &(y->bstnode);  

  // transfer of x's right child, y's left child
  x->bstnode.right = &(B->bstnode);
  y->bstnode.left = &(x->bstnode);

}

void RightRotate(AVLNode* y)
{
  AVLNode* x = (AVLNode*)((y->bstnode).left);
  AVLNode* B = (AVLNode*)((y->bstnode).right->left);

  // transfer of parent
  x->bstnode.parent = y->bstnode.parent;
  y->bstnode.parent = &(x->bstnode);

  y->bstnode.left = &(B->bstnode);
  x->bstnode.right = &(y->bstnode);
}
