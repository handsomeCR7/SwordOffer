#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int replaceBlank(char string[], int length) {
        char* array = new char[length * 3];
        int size = 0;
        for (int i = 0; i < length; i++) {
            char c = string[i];
            if (c == ' ') {
                array[size++] = '%';
                array[size++] = '2';
                array[size++] = '0';
            }
            else {
                array[size++] = c;
            }
        }
        for (int i = 0; i < size; i++) {
            string[i] = array[i];
        }
        return size;
    }
};

int main() {
    char string[] = "Mr John Smith";
    int length = 13;
    Solution s;
    cout << s.replaceBlank(string, length) <<endl;
    system("pause");
    return 0;
}