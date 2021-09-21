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
    template <typename T>
    void backAppend(vector<T>& firstVector,const vector<T> secondVector) {
        for (auto it = secondVector.cbegin(); it != secondVector.cend(); it++) {
            firstVector.push_back(*it);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results{};
        if (root == nullptr) {
            return results;
        }
        if (root->left != nullptr) {
            results = inorderTraversal(root->left);
        }
        results.push_back(root->val);
        if (root->right != nullptr) {
            backAppend(results, inorderTraversal(root->right));
        }

        return results;
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
    vector<int> v1 = sol->inorderTraversal(root);
    
    cout << v1 << endl;
    root->left = new TreeNode(3);
    root->right = new TreeNode(9);
    root->right->left = new TreeNode(7);
    v1 = sol->inorderTraversal(root);
    cout << v1 << endl;
}
