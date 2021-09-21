#include <vector>
#include <iostream>
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

template <class T>
ostream& operator<<(ostream& os, vector<T>& nums) {
    for (typename vector<T>::iterator p = nums.begin(); p != nums.end(); ++p) {
        os << *p << ' ';
    }
    return os;
}

int main()
{
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(5);
    cout << sol->maxDepth(root) << endl;
    
    root->left = new TreeNode(3);
    root->right = new TreeNode(9);
    root->right->left = new TreeNode(7);
    cout << sol->maxDepth(root) << endl;

    root->left = new TreeNode(9);
    root->left->right = new TreeNode(7);
    cout << sol->maxDepth(root) << endl;
}
