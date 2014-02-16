typedef struct Node {
  enum color {
    red,
    black
  } color;
  int key;
  struct Node* left, right, p;
} Node;

class RedBlackTree
{
  Node* nil;
  Node* root;
  RedBlackTree();
  void LEFT_ROTATE(Node* x);
  void RIGHT_ROTATE(Node* y);
  void RB_INSERT(int key);
  void RB_INSERT_FIXUP(Node* z);
};
