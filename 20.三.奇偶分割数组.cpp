#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void partitionArray(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int temp = 0;
        while (i < j) {
            if (nums[i] % 2 == 0 && nums[j] % 2 == 1) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
            else if (nums[i] % 2 == 0 && nums[j] % 2 != 1) {
                j--;
            }
            else if (nums[i] % 2 != 0 && nums[j] % 2 == 1) {
                i++;
            }
            else {
                i++;
                j--;
            }
        }
    }
};

int main() {
    vector<int> nums = { 1, 2, 3, 4 };
    Solution s;
    s.partitionArray(nums);
    system("pause");
    return 0;
}