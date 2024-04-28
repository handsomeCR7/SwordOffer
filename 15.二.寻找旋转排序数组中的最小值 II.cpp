#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//    int findMin(vector<int>& nums) {
//        int res = nums[0];
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] < res) {
//                res = nums[i];
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    void myfindMin(vector<int>& nums, int left, int right) {
        while (left < right) {
            if (nums[left] < nums[right]) {
                res = nums[left];
                return;
            }
            if (nums[left] > nums[(left + right) / 2]) {
                right = (left + right) / 2;
            }
            else if (nums[left] < nums[(left + right) / 2]) {
                left = (left + right) / 2 + 1;
            }
            else {
                // 找左边
                int temp = right;
                right = (left + right) / 2;
                myfindMin(nums, left, right);
                // 找右边
                left = (left + temp) / 2 + 1;
                myfindMin(nums, left, temp);
            }
            if (nums[left] < res) {
                res = nums[left];
            }
        }
    }
    int res;
    int findMin(vector<int>& nums) {
        res = nums[0];
        int left = 0;
        int right = nums.size() - 1;
        myfindMin(nums, left, right);
        return res;
    }
};

int main() {
    vector<int> nums = { 1,1,1,1,-1,1 };
    Solution s;
    cout << s.findMin(nums) << endl;
    system("pause");
    return 0;
}