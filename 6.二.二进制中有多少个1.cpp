#include<iostream>
using namespace std;

class Solution {
public:
    int countOnes(int num) {
        int res = 0;
        for (int i = 0; i < 32; i++){  
            if ((num & 1) == 1) {
                res++;
            }
            num >>= 1;
        }
        return res;
    }
};

int main() {
    int num = 0;
    Solution s;
    cout << s.countOnes(num) << endl;
    system("pause");
    return 0;
}