#include<iostream>
using namespace std;

// Definition of singly-linked-list:
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
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* after = head->next;
        while (cur != nullptr) {
            after = cur->next;
            cur->next = pre;
            pre = cur;
            cur = after;
        }
        return pre;
    }
};

int main() {
    ListNode* n0 = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    n0->next = n1;
    n1->next = n2;
    n2->next = nullptr;
    Solution s;
    s.reverse(n0);
    system("pause");
    return 0;
}