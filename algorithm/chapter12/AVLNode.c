#include "AVLNode.h"
#include <stdio.h>
#include <stdlib.h>

AVLNode*
BuildAVLTree()
{
  AVLNode* root;
  root = NULL;
  TreeInsertAVL(&root, 8, NULL);
  TreeInsertAVL(&root, 7, NULL);
  TreeInsertAVL(&root, 5, NULL);
  TreeInsertAVL(&root, 4, NULL);
  TreeInsertAVL(&root, 3, NULL);
  TreeInsertAVL(&root, 6, NULL);
  TreeInsertAVL(&root, 2, NULL);
  TreeInsertAVL(&root, 1, NULL);
  return root;
}

#ifdef DEBUG
void
printAVLNode(AVLNode* x)
{
  BSTNode* xx = (BSTNode*)x;
  printf("%x: Key %d, Balance %d, Parent %x, Left %x, Right %x\n",
	 x, xx->key, x->balance, xx->parent, xx->left, xx->right
	 );
}
#endif

AVLNode*
TreeInsertAVL(AVLNode** root, int key, void* memory)
{
  AVLNode* x;
  if (memory != NULL) {
    x = (AVLNode*)memory;
  } else {
    x = (AVLNode*)malloc(sizeof(AVLNode));
  }
  BSTNode* temp = (BSTNode*)(*root);
  if (*root == NULL) {
    *root = (AVLNode*)TreeInsert(&temp, key, (void*)x);
  } else {
    TreeInsert(&temp, key, (void*)x);
  }
  // from x, manage x's balance.
  x->balance = equal;
#ifdef DEBUG
  printAVLNode(x);
#endif
  TreeBalanceAVL(root, x, x->balance);
  return x;
}

void TreeBalanceAVL(AVLNode** root, AVLNode* elem, Balance bal)
{
  // elem itself is balanced, we check their father.
  BSTNode* p1b = (elem->bstnode).parent;
  if (p1b == NULL) {
#ifdef DEBUG
    printf("  End of balance: Root\n");
#endif
    return;
  }
  AVLNode* p1 = (AVLNode*)(elem->bstnode).parent;
  AVLNode* temp;
  if (p1b->left == &elem->bstnode) {
#ifdef DEBUG
    printf("  Element is added to left child, parent left is reduced\n");
#endif
    p1->balance --;
    if (p1->balance == left) {
#ifdef DEBUG
      printf("    If parent is left, pass on to the top\n");
#endif
      TreeBalanceAVL(root, p1, left);
    } else if (p1->balance == overleft) {
#ifdef DEBUG
      printf("    If parent is overleft, Rotate\n");
#endif
      // rotate
      if (bal == left) {
#ifdef DEBUG
	printf("      when current node is left, right rotate\n");
#endif
	RightRotate(p1);
	elem->balance = equal;
	p1->balance = equal;
	if (*root == p1) {
#ifdef DEBUG
	  printf("        root change\n");
#endif
	  *root = elem;
	}
#ifdef DEBUG
	printf("      End of balance: Right rotate\n");
#endif
      } else if (bal == right) {
#ifdef DEBUG
	printf("      when current node is right, double rotate\n");
#endif
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
	if (*root == p1) {
#ifdef DEBUG
	  printf("        root change\n");
#endif
	  *root = temp;
	}
#ifdef DEBUG
	printf("      End of balance: Left Right rotate\n");
#endif
      }
    }
  } else {
#ifdef DEBUG
    printf("  Element is added to right child, parent balance going up\n");
#endif
    p1->balance ++;
    if (p1->balance == right) {
#ifdef DEBUG
      printf("    If parent is right, pass on to the top\n");
#endif
      TreeBalanceAVL(root, p1, right);
    } else if (p1->balance == overright) {
#ifdef DEBUG
      printf("    If parent is overright, Rotate\n");
#endif
      // rotate;
      if (bal == right) {
#ifdef DEBUG
	printf("      when current node is right, left rotate\n");
#endif
	LeftRotate(p1);
	elem->balance = equal;
	p1->balance = equal;
	if (*root == p1) {
	  *root = elem;
#ifdef DEBUG
	  printf("        root change\n");
#endif
	}
#ifdef DEBUG
        printf("      End of balance: Left rotate\n");
#endif
      } else if (bal == left) {
#ifdef DEBUG
	printf("      when current node is right, double rotate\n");
#endif
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
	if (*root == p1) {
#ifdef DEBUG
	  printf("        root change\n");
#endif
	  *root = temp;
	}
#ifdef DEBUG
	printf("      End of balance: Right Left rotate\n");
#endif
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
  if (x->bstnode.parent != NULL) {
    if (x->bstnode.parent->left == &(x->bstnode))
      x->bstnode.parent->left = &(y->bstnode);
    else
      x->bstnode.parent->right = &(y->bstnode);
  }
  x->bstnode.parent = &(y->bstnode);

  // transfer of x's right child, y's left child
  x->bstnode.right = &(B->bstnode);
  y->bstnode.left = &(x->bstnode);
  if (B != NULL) {
    B->bstnode.parent = &(x->bstnode);
  }
}

void RightRotate(AVLNode* y)
{
  AVLNode* x = (AVLNode*)((y->bstnode).left);
  AVLNode* B = (AVLNode*)((y->bstnode).left->right);

  // transfer of parent
  x->bstnode.parent = y->bstnode.parent;
  if (y->bstnode.parent != NULL) {
    if (y->bstnode.parent->left == &(y->bstnode))
      y->bstnode.parent->left = &(x->bstnode);
    else
      y->bstnode.parent->right = &(x->bstnode);
  }
  y->bstnode.parent = &(x->bstnode);

  y->bstnode.left = &(B->bstnode);
  x->bstnode.right = &(y->bstnode);
  if (B != NULL) {
    B->bstnode.parent = &(y->bstnode);
  }
}
