#include "RedBlackTree.h"
#include <stddef.h>

RedBlackTree::RedBlackTree()
{
  nil = new Node;
  root = nil;
  nil->color = Node::black;
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
  Node* y = nil; // 1
  Node* x = root; // 2
  while (x != nil) { // 3
    y = x; // 4
    if (key < x->key) // 5
      x = x->left; // 6
    else
      x = x->right; // 7
  }
  z->p = y; // 8
  if (y == nil) // 9
    root = z; // 10
  else if(z->key < y->key) // 11
    y->left = z; // 12
  else
    y->right = z; // 13
  z->left = nil; // 14
  z->right = nil; // 15
  z->color = Node::red; // 16
  RB_INSERT_FIXUP(z); // 17
}

void RedBlackTree::RB_INSERT_FIXUP(Node* z)
{
  Node* y;
  while (z->p->color == Node::red) // 1 double red, violation
    if (z->p == z->p->p->left) { // 2
      y = z->p->p->right; // 3
      if (y->color == Node::red) { // 4 case 1: uncle is red, change both children into black, change root into red
	z->p->color = Node::black; // 5
	y->color = Node::black; // 6
	z->p->p->color = Node::red; // 7 next iteration, because root is changed into red
	z = z->p->p; // 8
      } else {
        if (z == z->p->right) { // 9 case 2: rotate to left and down to case 3
          z = z->p; // 10
	  LEFT_ROTATE(z); // 11
        }
        z->p->color = Node::black; // 12 case 3: 
        z->p->p->color = Node::red; // 13
        RIGHT_ROTATE(z->p->p); // 14
      }
    } else { // 15
      y = z->p->p->left;
      if (y->color == Node::red) {
	z->p->color = Node::black;
	y->color = Node::black;
	z->p->p->color = Node::red;
	z = z->p->p;
      } else {
        if (z == z->p->left) {
      	  z = z->p;
	  RIGHT_ROTATE(z);
        }
        z->p->color = Node::black;
        z->p->p->color = Node::red;
        LEFT_ROTATE(z->p->p);
      }
    }
  root->color = Node::black; // 16
}

void
RedBlackTree::RB_TRANSPLANT(Node* const u, Node* const v)
{
  if(u->p == nil)
    root = v;
  else if(u == u->p->left)
    u->p->left = v;
  else
    u->p->right = v;
  v->p = u->p;
}

inline Node*
RedBlackTree::TREE_MINIMUM(Node* root)
{
  while (root->left != nil)
    root = root->left;
  return root;
}

void
RedBlackTree::RB_DELETE(Node* const z)
{
  Node *y = z, *x; // 1
  enum Node::color y_original_color = y->color; // 2
  if (z->left == nil) { // 3 Z has only one child
    x = z->right; // 4
    RB_TRANSPLANT(z, z->right); // 5
  } else if (z->right == nil) { // 6
    x = z->left; // 7
    RB_TRANSPLANT(z, z->left); // 8 
  } else { // z has two child
    y = TREE_MINIMUM(z->right); // 9
    y_original_color = y->color; // 10
    x = y->right; // 11
    if (y->p == z) // 12 if y == z->right 
      x->p = y; // 13 useless ?
    else {
      RB_TRANSPLANT(y, y->right); // 14 move y->right to position y
      y->right = z->right; // 15 link z->right to y;
      y->right->p = y; // 16
    }
    RB_TRANSPLANT(z, y); // 17 replace z with y;
    y->left = z->left; // 18 link z->left to y;
    y->left->p = y; // 19
    y->color = z->color; // 20 replace z color to y
  }
  if (y_original_color == Node::black) // 21
    RB_DELETE_FIXUP(x); // 22
  delete z;
}

void
RedBlackTree::RB_DELETE_FIXUP(Node* x)
{
  Node* w;
  while (x != root && x->color == Node::black)
    if (x == x->p->left) {
      w = x->p->right;
      if (w->color == Node::red) {
        w->color = Node::black;
        x->p->color = Node::red;
        LEFT_ROTATE(x->p);
        w = x->p->right;
      }
      if (w->left->color == Node::black && w->right->color == Node::black) {
        w->color = Node::red;
        x = x->p;
      }
      else {
        if (w->right->color == Node::black) {
          w->left->color = Node::black;
          w->color = Node::red;
          RIGHT_ROTATE(w);
          w = x->p->right;
        }
        w->color = x->p->color;
        x->p->color = Node::black;
        w->right->color = Node::black;
        LEFT_ROTATE(x->p);
        x = root;
      }
    } else {
      w = x->p->left;
      if (w->color == Node::red) {
        w->color = Node::black;
        x->p->color = Node::red;
        RIGHT_ROTATE(x->p);
        w = x->p->left;
      }
      if (w->right->color == Node::black && w->left->color == Node::black) {
        w->color = Node::red;
        x = x->p;
      }
      else {
        if (w->left->color == Node::black) {
          w->right->color = Node::black;
          w->color = Node::red;
          LEFT_ROTATE(w);
          w = x->p->left;
        }
        w->color = x->p->color;
        x->p->color = Node::black;
        w->left->color = Node::black;
        RIGHT_ROTATE(x->p);
        x = root;
      }     
    }
  x->color = Node::black;
}
