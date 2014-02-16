#include "RedBlackTree.h"
#include <stddef.h>

RedBlackTree::RedBlackTree()
{
  nil->color = black;
}

void RedBlackTree::LEFT_ROTATE(Node* x)
{
  Node* y = x->right; // set y
  x->right = y->left; // turn y's left subtree into x's right subtree
  if (y->left != nil)
    y->left->p = x;
  y->p = x->p; // link x's parent to y;
  if (x->p == nil)
    root = y;
  else if (x == x->p->left)
    x->p->left = y;
  else
    x->p->right = y;
  y->left = x; // put x on y's left
  x->p = y;
}

void RedBlackTree::RIGHT_ROTATE(Node* y)
{
  Node* x = y->left; // set x
  y->left = x->right;
  if (x->right != nil)
    x->right->p = y;

  y->p = x->p;
  if (y->p == nil)
    root = x;
  else if (y == y->p->left)
    y->p->left = x;
  else
    y->p->right = x;
  x->right = y;
  y->p = x;
}

void RedBlackTree::RB_INSERT(int key)
{
  Node* z = new Node;
  z->key = key;
  Node* y = nil;
  Node* x = root;
  while (x != nil) {
    y = x;
    if (key < x->key)
      x = x->left;
    else
      x = x->right;
  }
  z->p = y;
  if (y == nil)
    root = z;
  else if(z->key < y->key)
    y->left = z;
  else
    y->right = z;
  z->left = nil;
  z->right = nil;
  z->color = RED;
  RB_INSERT_FIXUP(z);
}

void RedBlackTree::RB_INSERT_FIXUP(Node* z)
{
  Node* y;
  while (z->p->color == red)
    if (z->p == z->p->p->left) {
      y = z->p->p->right;
      if (y->color == red) {
	z->p->color = black;
	y->color = black;
	z->p->p->color = red;
	z = z->p->p;
      } else if (z == z->p->right) {
	z = z->p;
	LEFT_ROTATE(z);
      }
      z->p->color = black;
      z->p->p->color = red;
      RIGHT_ROTATE(z->p->p);
    } else {
      y = z->p->p->left;
      if (y->color == red) {
	z->p->color = black;
	y->color = black;
	z->p->p->color = red;
	z = z->p->p;
      } else if (z = z->p->left) {
	z = z->p;
	RIGHT_ROTATE(z);
      }
      z->p->color = black;
      z->p->p->color = red;
      LEFT_ROTATE(z->p->p);
    }
  root->color = black;
}

