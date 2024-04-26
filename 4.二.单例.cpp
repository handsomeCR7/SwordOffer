#include<iostream>
using namespace std;

class Solution {
public:
    static Solution* instance;
    static Solution* getInstance() {
        if (instance == NULL) {
            instance = new Solution();
        }
        return instance;
    }
};

Solution* Solution::instance = NULL;

int main() {
    Solution a;
    Solution *aa = a.getInstance();
    //第一次,instance为null，进循环，给instance赋值，将instance从null变为XXXXXX
    Solution b;
    Solution* bb = b.getInstance();
    //第二次，instance不为null，不进循环，后面每一次就直接返回XXXXXX

    system("pause");
    return 0;
}