#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
  nil = new RBNode;
  root = nil;
  nil->color = RBNode::black;
}

void RedBlackTree::LEFT_ROTATE(RBNode* x)
{
  RBNode* y = x->right; // set y
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

void RedBlackTree::RIGHT_ROTATE(RBNode* y)
{
  RBNode* x = y->left; // set x
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

void
RedBlackTree::RB_INSERT(int key)
{
  BSNode* z = new Node();
  z->key = key;
  RB_INSERT(z);
}

void
RedBlackTree::RB_INSERT(RBNode* z)
{
  RBNode* y = nil; // 1
  RBNode* x = root; // 2
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
  z->color = RBNode::red; // 16
  RB_INSERT_FIXUP(z); // 17
}

void RedBlackTree::RB_INSERT_FIXUP(RBNode* z)
{
  RBNode* y;
  while (z->p->color == RBNode::red) // 1 double red, violation
    if (z->p == z->p->p->left) { // 2
      y = z->p->p->right; // 3
      if (y->color == RBNode::red) { // 4 case 1: uncle is red, change both children into black, change root into red
	z->p->color = RBNode::black; // 5
	y->color = RBNode::black; // 6
	z->p->p->color = RBNode::red; // 7 next iteration, because root is changed into red
	z = z->p->p; // 8
      } else {
        if (z == z->p->right) { // 9 case 2: rotate to left and down to case 3
          z = z->p; // 10
	  LEFT_ROTATE(z); // 11
        }
        z->p->color = RBNode::black; // 12 case 3: 
        z->p->p->color = RBNode::red; // 13
        RIGHT_ROTATE(z->p->p); // 14
      }
    } else { // 15
      y = z->p->p->left;
      if (y->color == RBNode::red) {
	z->p->color = RBNode::black;
	y->color = RBNode::black;
	z->p->p->color = RBNode::red;
	z = z->p->p;
      } else {
        if (z == z->p->left) {
      	  z = z->p;
	  RIGHT_ROTATE(z);
        }
        z->p->color = RBNode::black;
        z->p->p->color = RBNode::red;
        LEFT_ROTATE(z->p->p);
      }
    }
  root->color = RBNode::black; // 16
}

void
RedBlackTree::RB_TRANSPLANT(RBNode* const u, RBNode* const v)
{
  if(u->p == nil)
    root = v;
  else if(u == u->p->left)
    u->p->left = v;
  else
    u->p->right = v;
  v->p = u->p;
}

RBNode*
RedBlackTree::INTERACTIVE_TREE_SEARCH(int key)
{
  RBNode *y = root;
  while (root != nil && key != y->key) {
    if (key < y->key)
      y = y->left;
    else
      y = y->right;
  }
  return root;
}

void
printNode(RBNode* node)
{
  printf("%3d", node->key);
}

void
RedBlackTree::INORDER_TREE_WALK(RBNode* y, void (*func)(RBNode* node))
{
  if (y != nil) {
    INORDER_TREE_WALK(y->left, func);
    (*func)(y);
    INORDER_TREE_WALK(y->right, func);
  }
}

void
RedBlackTree::RB_DELETE(int key)
{
  RBNode *y = INTERACTIVE_TREE_SEARCH(key);
  if (y != nil)
    RB_DELETE(y);
}

RBNode*
RedBlackTree::TREE_MINIMUM(RBNode* root)
{
  while (root->left != nil)
    root = root->left;
  return root;
}


void
RedBlackTree::RB_DELETE(RBNode* const z)
{
  RBNode *y = z, *x; // 1
  enum RBNode::color y_original_color = y->color; // 2
  if (z->left == nil) { // 3 Z has only one child
    x = z->right; // 4
    RB_TRANSPLANT(z, z->right); // 5
  } else if (z->right == nil) { // 6
    x = z->left; // 7
    RB_TRANSPLANT(z, z->left); // 8 
  } else { // z has two child
    y = dynamic_cast<RBNode*>(TREE_MINIMUM(z->right)); // 9
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
  if (y_original_color == RBNode::black) // 21
    RB_DELETE_FIXUP(x); // 22
  delete z;
}

void
RedBlackTree::RB_DELETE_FIXUP(RBNode* x)
{
  RBNode* w;
  while (x != root && x->color == RBNode::black)
    if (x == x->p->left) {
      w = x->p->right;
      if (w->color == RBNode::red) {
        w->color = RBNode::black;
        x->p->color = RBNode::red;
        LEFT_ROTATE(x->p);
        w = x->p->right;
      }
      if (w->left->color == RBNode::black && w->right->color == RBNode::black) {
        w->color = RBNode::red;
        x = x->p;
      }
      else {
        if (w->right->color == RBNode::black) {
          w->left->color = RBNode::black;
          w->color = RBNode::red;
          RIGHT_ROTATE(w);
          w = x->p->right;
        }
        w->color = x->p->color;
        x->p->color = RBNode::black;
        w->right->color = RBNode::black;
        LEFT_ROTATE(x->p);
        x = root;
      }
    } else {
      w = x->p->left;
      if (w->color == RBNode::red) {
        w->color = RBNode::black;
        x->p->color = RBNode::red;
        RIGHT_ROTATE(x->p);
        w = x->p->left;
      }
      if (w->right->color == RBNode::black && w->left->color == RBNode::black) {
        w->color = RBNode::red;
        x = x->p;
      }
      else {
        if (w->left->color == RBNode::black) {
          w->right->color = RBNode::black;
          w->color = RBNode::red;
          LEFT_ROTATE(w);
          w = x->p->left;
        }
        w->color = x->p->color;
        x->p->color = RBNode::black;
        w->left->color = RBNode::black;
        RIGHT_ROTATE(x->p);
        x = root;
      }     
    }
  x->color = RBNode::black;
}


