#include<iostream>
using namespace std;

class Solution {
public:
    int fastPower(int a, int b, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return a % b;
        }
        long long temp = fastPower(a, b, n / 2);
        if (n % 2 == 0) {
            return (temp * temp) % b;
        }
        else {
            return ((temp * temp) % b * a) % b;
        }
    }
};

int main() {
    int a = 3;
    int b = 7;
    int n = 5;
    Solution s;
    cout << s.fastPower(a, b, n) << endl;
    system("pause");
    return 0;
}