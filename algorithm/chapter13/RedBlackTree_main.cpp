#include "RedBlackTree.h"
#include <cstdio>

using namespace std;

void
inorder_tree_walk(RedBlackTree& tree, Node* p)
{
  printf("%s:%d ", (p->color == Node::black)?"black":"red", p->key);
  if (p->left != tree.nil)
    inorder_tree_walk(tree, p->left);
  if (p->right != tree.nil)
    inorder_tree_walk(tree, p->right);
}

int
main(int argc, char* argv[])
{
  RedBlackTree rb_tree;
  rb_tree.RB_INSERT(26);
  rb_tree.RB_INSERT(17);
  rb_tree.RB_INSERT(41);
  rb_tree.RB_INSERT(14);
  rb_tree.RB_INSERT(21);
  rb_tree.RB_INSERT(30);
  rb_tree.RB_INSERT(47);
  rb_tree.RB_INSERT(10);
  rb_tree.RB_INSERT(16);
  rb_tree.RB_INSERT(19);
  rb_tree.RB_INSERT(21);
  rb_tree.RB_INSERT(28);
  rb_tree.RB_INSERT(38);
  rb_tree.RB_INSERT(7);
  rb_tree.RB_INSERT(12);
  rb_tree.RB_INSERT(14);
  rb_tree.RB_INSERT(20);
  rb_tree.RB_INSERT(36);
  rb_tree.RB_INSERT(39);
  rb_tree.RB_INSERT(3);
  inorder_tree_walk(rb_tree, rb_tree.root);
  rb_tree.RB_DELETE(rb_tree.root);
  inorder_tree_walk(rb_tree, rb_tree.root);
}
