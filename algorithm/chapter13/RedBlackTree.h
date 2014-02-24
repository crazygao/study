//Red-Black Tree
//1 Every Node is either red or black
//2 Root is black
//3 Every Leaf Nil is black
//4 If a node is red, then both it's children are black
//5 For Each Node, all simple paths from the node to descendant leaves contain the same number of black nodes
#ifndef REDBLACKTREE
#define REDBLACKTREE
typedef struct Node {
  enum color {
    red,
    black
  } color;
  int key;
  struct Node *left, *right, *p;
} Node;

class RedBlackTree
{
public:
  Node* nil;
  Node* root;
  RedBlackTree();
  void LEFT_ROTATE(Node* x);
  void RIGHT_ROTATE(Node* y);
  void RB_INSERT(int key);
  void RB_INSERT_FIXUP(Node* z);
  void RB_TRANSPLANT(Node* const u, Node* const v);
  void RB_DELETE(Node* const z);
  void RB_DELETE_FIXUP(Node* x);
  Node* TREE_MINIMUM(Node* root);
};
#endif
