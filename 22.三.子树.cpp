#include<iostream>
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
    bool compare(TreeNode* t1, TreeNode* t2) {
        // 两者只要有一个提前遍历到空节点，就算前面都一样，也不算
        if (t1 == NULL && t2 != NULL)
            return 0;
        if (t1 != NULL && t2 == NULL)
            return 0;
        if (t1 == NULL && t2 == NULL)
            return 1;
        if (t1->val != t2->val) {
            return 0;
        }
        return compare(t1->left, t2->left) && compare(t1->right, t2->right);
    }
    // dfs用来遍历t1的各个节点
    // compare用来比较以dfs遍历到的节点为根节点的子树是否和t2一样
    void dfs(TreeNode* t1, TreeNode* t2) {
        if (compare(t1, t2) == 1) {
            res = 1;
            return;
        }
        if (t1 == NULL) {
            return;
        }
        
        dfs(t1->left, t2);
        dfs(t1->right, t2);
    }

    bool isSubtree(TreeNode* t1, TreeNode* t2) {
        dfs(t1, t2);
        return res;
    }

    bool res = 0;
};

int main() {
    TreeNode* n0 = new TreeNode(1);
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(3);
    TreeNode* n3 = new TreeNode(4);
    n0->left = n1;
    n0->right = n2;
    n2->left = n3;

    TreeNode* m0 = new TreeNode(3);
    TreeNode* m1 = new TreeNode(4);
    m0->left = m1;

    Solution s;
    cout << s.isSubtree(n0, m0) << endl;
    system("pause");
    return 0;
}