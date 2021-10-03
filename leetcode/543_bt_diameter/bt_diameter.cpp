#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int h = 0;
        int hl = height(root->left);
        if (hl > 0) {
            h += hl + 1;
        }
        int hr = height(root->right);
        if (hr > 0) {
            h += hr + 1;
        }
        return h;
    }
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        int hl = root->left == nullptr ? 0: height(root->left);
        int hr = root->right == nullptr ? 0: height(root->right);
        return max(hl + 1, hr + 1);
    }
};
