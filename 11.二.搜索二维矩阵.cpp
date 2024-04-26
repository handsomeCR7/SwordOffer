#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;
        int mid = (left + right) / 2;
        while (left < right) {
            mid = (left + right) / 2;
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target) {
                left = mid + 1;
            }
            else if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] > target) {
                right = mid - 1;
            }
            else {
                return 1;
            }
            
        }
        if (matrix[left / matrix[0].size()][left % matrix[0].size()] == target) {
            return 1;
        }
        return 0;
    }
};



int main() {
    vector<vector<int>> matrix = { {1, 4, 5},{6, 7, 8} };
    int target = 6;
    Solution s;
    cout << s.searchMatrix(matrix, target) << endl;
    system("pause");
    return 0;
}