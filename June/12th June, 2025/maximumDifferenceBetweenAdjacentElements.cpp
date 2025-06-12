// Leetcode question no 3423

/*
Given a circular array nums, find the maximum absolute difference between adjacent elements.

Note: In a circular array, the first and last elements are adjacent.
*/

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDifference = INT_MIN;
        for(int i = 0; i <= n; i++) {
            maxDifference = max(maxDifference, abs(nums[i%n]-nums[(i+1)%n]));
        }
        return maxDifference;
    }
};