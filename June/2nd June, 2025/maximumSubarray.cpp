// Leetcode question no 53

/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(maximum < sum) maximum = sum;
            if(sum < 0) sum = 0;
        }
        return maximum;
    }
};