#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int a = 1;
        int b = 2;
        int t = 2;
        for (int i = 3; i <= n; i++) {
            t = b;
            b += a;
            a = t;
        }
        return b;
    }
};

int main() {
    int n = 5;
    Solution s;
    cout << s.climbStairs(n) << endl;
    system("pause");
    return 0;
}