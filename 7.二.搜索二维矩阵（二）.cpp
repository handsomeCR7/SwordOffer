#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1;
        int size = matrix[0].size();
        int j = 0;
        int res = 0;
        while (i >= 0 && j <= size - 1) {
            if (matrix[i][j] > target) {
                i--;
            }
            else if (matrix[i][j] < target) {
                j++;
            }
            else {
                res++;
                i--;
                j++;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = { {} };
    int target = 1;
    Solution s;
    cout << s.searchMatrix(matrix, target) << endl;
    system("pause");
    return 0;
}