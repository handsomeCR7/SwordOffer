#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void mynumbersByRecursion(int n, int ans) {
        // 在最底层才push_back;
        if (n == 0) {
            if (ans > 0) {
                res.push_back(ans);
            }
            return;
        }
        
        for (int i = 0; i <= 9; i++) {
            mynumbersByRecursion(n - 1, 10 * ans + i);
        }
    }

    vector<int> numbersByRecursion(int n) {
        mynumbersByRecursion(n, 0);
        return res;
    }

    vector<int> res;
};

int main() {
    int n = 2;
    Solution s;
    s.numbersByRecursion(n);
    system("pause");
    return 0;
}