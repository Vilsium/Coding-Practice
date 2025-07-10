// Leetcode question 1

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int rem = target - num;
            if (mpp.find(rem) != mpp.end()) {
                ans.push_back(mpp[rem]);
                ans.push_back(i);
                break;
            }
            mpp[num] = i;
        }
        return ans;
    }
};