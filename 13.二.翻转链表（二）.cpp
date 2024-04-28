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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* a = NULL;     // m-1
        ListNode* a1 = head;    // m
        ListNode* b = NULL;     // n+1
        ListNode* b1 = head;    // n
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* after = NULL;
        for (int i = 1; i <= n; i++) {
            if (i == m - 1) {
                a = cur;
            }
            else if (i == m) {
                a1 = cur;
                cur = a1;
                after = cur->next;
            }
            if (i == n) {
                b1 = cur;
                b = cur->next;
            }
            if (i >= m && i <= n) {
                after = cur->next;
                cur->next = pre;
                pre = cur;
                cur = after;
            }
            else {
                cur = cur->next;
            }
        }
        a1->next = cur;
        if (a == NULL) {
            return pre;
        }
        a->next = pre;
        return head;
    }
};

int main() {
    ListNode* n1 = new ListNode(5);
    /*ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);*/
    /*n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;*/
    int m = 1;
    int n = 1;
    Solution s;
    s.reverseBetween(n1, m, n);
    system("pause");
    return 0;
}

