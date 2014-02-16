
typedef struct BSTNode// Binary Search Tree Node
{
  struct BSTNode* parent;
  struct BSTNode* left;
  struct BSTNode* right;
  int key;
} BSTNode;

BSTNode* BuildTestTree();
void TreeInsert(BSTNode* node, int key);
BSTNode* TREE_SEARCH(BSTNode* root, int key);
BSTNode* INTERACTIVE_TREE_SEARCH(BSTNode* root, int key);
BSTNode* TREE_MINIMUM(BSTNode* root);
BSTNode* TREE_MAXIMUM(BSTNode* root);
BSTNode* TREE_SUCCESSOR(BSTNode* node);
BSTNode* TREE_PREDECESSOR(BSTNode* node);

///Description: look at the map on the book, it's good enough
// for explaination
void TRANSPLANT(BSTNode* T, BSTNode* u, BSTNode* v);
void TREE_DELETE(BSTNode* T,BSTNode* z);


void INORDER_TREE_WALK(BSTNode* root, void (*func)(BSTNode* node));
void printNode(BSTNode* node);
