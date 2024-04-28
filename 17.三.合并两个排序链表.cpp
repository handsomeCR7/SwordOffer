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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode* cur = res;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        // 有一个空了
        if (l1 == NULL) {
            cur->next = l2;
        }
        else {
            cur->next = l1;
        }
        return res->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(NULL);
    ListNode* l2 = new ListNode(0);
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(3);
    l2->next = n1;
    n1->next = n2;
    Solution s;
    s.mergeTwoLists(l1, l2);
    system("pause");
    return 0;
}