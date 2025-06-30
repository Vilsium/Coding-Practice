// Leetcode question 594

/*
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i : nums) {
            mpp[i]++;
        }
        int answer = 0;
        for(auto it : mpp) {
            if(mpp.find(it.first+1) != mpp.end()) answer = max(answer, mpp[it.first] + mpp[it.first+1]);
        }
        return answer;
    }
};