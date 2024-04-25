#include<iostream>
using namespace std;

class Solution {
public:
    int fibonacci(int n) {
        if (n == 1) {
            return 0;
        }
        int a = 0;
        int b = 1;
        int t = 0;
        for (int i = 3; i <= n; i++) {
            t = b;
            b = a + b;
            a = t;
        }
        return b;
    }
};

int main() {
    int n = 5;
    Solution s;
    cout << s.fibonacci(n) << endl;
    system("pause");
    return 0;
}