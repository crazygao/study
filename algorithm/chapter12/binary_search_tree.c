#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

BSTNode* _root = NULL;

void
printNode(BSTNode* node)
{
  printf("%3d", node->key);
}

BSTNode*
TREE_SEARCH(BSTNode* root, int key)
{
  if (root == NULL || key == root->key)
    return root;
  if (key < root->key)
    return TREE_SEARCH(root->left, key);
  else
    return TREE_SEARCH(root->right, key);
}

BSTNode*
INTERACTIVE_TREE_SEARCH(BSTNode* root, int key)
{
  while(root!=NULL && key != root->key) {
    if (key < root->key)
      root = root->left;
    else
      root = root->right;
  }
  return root;
}

void
INORDER_TREE_WALK(BSTNode* root, void (*func)(BSTNode* node))
{
  if (root != NULL) {
    INORDER_TREE_WALK(root->left, func);
    (*func)(root);
    INORDER_TREE_WALK(root->right, func);
  }
}

void
TreeInsert(BSTNode* root, int key)
{
  BSTNode* y = NULL;
  BSTNode* z = (BSTNode*)malloc(sizeof(BSTNode));
  z->key = key;
  z->left = NULL;
  z->right = NULL;
  BSTNode* x = root;
  while (x != NULL) {
    y = x;
    if (key < x->key)
      x = x->left;
    else
      x = x->right;
  }
  z->parent = y;
  if (y == NULL)
    _root = z;
  else if (key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
}

BSTNode*
BuildTestTree()
{
  TreeInsert(_root, 6);//root
  TreeInsert(_root, 5);
  TreeInsert(_root, 7);
  TreeInsert(_root, 2);
  TreeInsert(_root, 5);
  TreeInsert(_root, 8);
  return _root;
}

BSTNode*
TREE_MINIMUM(BSTNode* root)
{
  while (root->left != NULL)
    root = root->left;
  return root;
}
BSTNode*
TREE_MAXIMUM(BSTNode* root)
{
  while (root->right != NULL)
    root = root->right;
  return root;
}

BSTNode*
TREE_SUCCESSOR(BSTNode* node)
{
  if (node->right != NULL)
    return TREE_MINIMUM(node->right);
  BSTNode* y = node->parent;
  while (y != NULL && node == y->right) {
    node = y;
    y = y->parent;
  }
  return y;
}

BSTNode*
TREE_PREDECESSOR(BSTNode* node)
{
  if (node->left != NULL)
    return TREE_MAXIMUM(node->left);
  BSTNode* y = node->parent;
  while(y != NULL && node == y->left) {
    node = y;
    y = y->parent;
  }
  return y;
}

void
TRANSPLANT(BSTNode* T, BSTNode* u, BSTNode* v)
{
  if (u->parent == NULL)
    T = v;
  else if (u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
  if (v != NULL)
    v->parent = u->parent;
}

void
TREE_DELETE(BSTNode* T,BSTNode* z)
{
  if (z->left == NULL)
    TRANSPLANT(T, z, z->right);
  else if (z->right == NULL)
    TRANSPLANT(T, z, z->left);
  else {
    BSTNode* y = TREE_MINIMUM(z->right);
    if (y->parent != z) {
      TRANSPLANT(T, y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    TRANSPLANT(T, z, y);
    y->left = z->left;
    y->left->parent = y;
  }
}
