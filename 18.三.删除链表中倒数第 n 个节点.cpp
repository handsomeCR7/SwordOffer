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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = head;
        ListNode* res = head;
        ListNode* cur = head;
        int i = 0;
        while (cur != 0) {
            if (i >= n) {
                res = res->next;
            }
            if (i >= n + 1) {
                pre = pre->next;
            }
            i++;
            cur = cur->next;
        }
        if (res == head) {
            return head->next;
        }
        pre->next = res->next;
        return head;
    }
};

int main() {


    system("pause");
    return 0;
}