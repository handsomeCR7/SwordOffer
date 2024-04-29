#include<iostream>
using namespace std;

// Definition of ListNode
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) {
            return;
        }
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
   
    Solution s;
    s.deleteNode(n1);
    system("pause");
    return 0;
}