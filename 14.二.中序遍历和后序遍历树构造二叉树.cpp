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

    TreeNode* mybuildTree(vector<int>& inorder, vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
        if (postorder_left > postorder_right) {
            return nullptr;
        }
        int postorder_root = postorder_right;
        int inorder_root = m[postorder[postorder_root]];
        //int inorder_root = find(inorder.begin(), inorder.end(), postorder[postorder_root]) - inorder.begin();
        TreeNode* root = new TreeNode(postorder[postorder_root]);
        int size_left_subtree = inorder_root - inorder_left;
        root->left = mybuildTree(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_left + size_left_subtree - 1);
        root->right = mybuildTree(inorder, postorder, inorder_root + 1, inorder_right, postorder_left + size_left_subtree, postorder_root - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        for (int i = 0; i < size; i++) {
            m[inorder[i]] = i;
        }
        return mybuildTree(inorder, postorder, 0, size - 1, 0, size - 1);
    }
};

int main() {
    vector<int> inorder = { 1, 2, 3 };
    vector<int> postorder = { 1, 3, 2 };
    Solution s;
    s.buildTree(inorder, postorder);
    system("pause");
    return 0;
}