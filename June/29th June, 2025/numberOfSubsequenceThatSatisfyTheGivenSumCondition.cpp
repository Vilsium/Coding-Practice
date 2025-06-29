// Leetcode question 1498

/*
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.
*/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1000000007;
        sort(nums.begin(), nums.end());
        vector<int> powers(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++) {
            powers[i] = (powers[i-1] * 2) % MOD;
        }
        int left  = 0, right = nums.size()-1;
        int answer = 0;
        while(left <= right) {
            if(nums[left] + nums[right] <= target) {
                answer = (answer + powers[right-left]) % MOD;
                left++;
            } else right--;
        }
        return answer;
    }
};