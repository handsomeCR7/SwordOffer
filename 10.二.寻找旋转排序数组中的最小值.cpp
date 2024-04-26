#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//    int findMin(vector<int>& nums) {
//        int res = nums[0];
//        for (int i = 1; i < nums.size(); i++) {
//            if (nums[i] < res) {
//                res = nums[i];
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left < right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            }
            else {
                mid = (left + right) / 2;
                if (nums[left] <= nums[mid]) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
        }
        return nums[left];
    }
};

int main() {
    vector<int> nums = { 2,1 };
    Solution s;
    cout << s.findMin(nums) << endl;
    system("pause");
    return 0;
}