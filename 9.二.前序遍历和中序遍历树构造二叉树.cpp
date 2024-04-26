#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode* left, * right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    unordered_map<int, int> m;
    TreeNode* mybuildTree(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        int preorder_root = preorder_left;
        int inorder_root = m[preorder[preorder_root]];
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorder_left;
        root->left = mybuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        root->right = mybuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }
        return mybuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

int main() {
    vector<int> preorder = { 2, 1, 3 };
    vector<int> inorder = { 1, 2, 3 };
    Solution s;
    s.buildTree(preorder, inorder);
    system("pause");
    return 0;
}