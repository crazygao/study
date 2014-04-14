#ifndef REDBLACKTREE
#define REDBLACKTREE

#include "../chapter12/binary_search_tree.h"

class RBNode: public BSTNode
{
public:
  enum color {red, black} color;
};

class RedBlackTree {
public:
  RBNode* nil;
  RBNode* root;
  RedBlackTree();
protected:
  void LEFT_ROTATE(RBNode* x);
  void RIGHT_ROTATE(RBNode* y);
public:
  void RB_INSERT(int key);
  void RB_INSERT(RBNode* z);
  void RB_DELETE(int key);
  void RB_DELETE(RBNode* const z);
private:
  void RB_TRANSPLANT(Node* const u, Node* const v);
  void RB_INSERT_FIXUP(RBNode* z);
  void RB_DELETE_FIXUP(RBNode* x)
}
#endif //REDBLACKTREE
