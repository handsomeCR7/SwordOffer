#include<iostream>
using namespace std;

class Solution {
public:
    char* m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char* pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution& object) {
        if (this->m_pData == object.m_pData) {
            return *this;
        }
        delete []m_pData;
        m_pData = NULL;
        if (object.m_pData == NULL) {
            return *this;
        }
        m_pData = new char[strlen(object.m_pData) + 1];
        strcpy(m_pData, object.m_pData);   // 使用strcpy进行拷贝，而不是*this->m_pData = *object.m_pData，因为解引用后是数组的第一个字符，只拷贝了单个字符
        return *this;   // 因为链式连等是从后往前，所以返回*this（而不是object）用于链式
    }
};

int main() {
    char a = 'a';
    Solution A;
    A.m_pData = &a;
    
    char b = 'bbb';
    Solution B;
    B.m_pData = &b;

    char c = 'cccc';
    Solution C;
    C.m_pData = &c;

    A = B;
    B = C;
    if (*A.m_pData == *B.m_pData) {
        cout << 1;
    }
   
    system("pause");
    return 0;
}