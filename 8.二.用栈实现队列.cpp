#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> A;
    stack<int> B;

    MyQueue() {
        
    }

    void push(int element) {
        A.push(element);
    }

    int pop() {
        if (B.empty() == 1) {
            while (A.empty() == 0) {
                B.push(A.top());
                A.pop();
            }
        }
        int res = B.top();
        B.pop();
        return res;
    }

    int top() {
        if (B.empty() == 1) {
            while (A.empty() == 0) {
                B.push(A.top());
                A.pop();
            }
        }
        return B.top();
    }
};

int main() {

    system("pause");
    return 0;
}