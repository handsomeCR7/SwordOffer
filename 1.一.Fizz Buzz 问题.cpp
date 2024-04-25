#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                res.push_back("fizz buzz");
            }
            else if (i % 3 == 0) {
                res.push_back("fizz");
            }
            else if (i % 5 == 0) {
                res.push_back("buzz");
            }
            else {
                res.push_back(to_string(i));
            }
        }
        return res;
    }
};

int main() {
    int n = 15;
    Solution s;
    s.fizzBuzz(n);
    system("pause");
    return 0;
}