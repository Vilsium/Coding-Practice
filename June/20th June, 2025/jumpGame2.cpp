// Leetcode question 45

/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int left = 0;
        int right = 0;
        while(right < nums.size()-1) {
            int farthest = 0;
            for(int i = left; i <= right; i++) {
                farthest = max(farthest, i+nums[i]);
            }
            left = right+1;
            right = farthest;
            jumps++;
        }
        return jumps;
    }
};