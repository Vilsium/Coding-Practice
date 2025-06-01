// Leetcode question no 977

/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
*/

/*
Solution 1: O(n logn)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        for(int i = 0; i < n; i++) {
        answer[i] = nums[i]*nums[i];
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};
*/

// Solution 2: O(n) Time Complexity
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int i = n-1;
        vector<int> answer(n);
        while(start <= end) {
            if(nums[end] >= abs(nums[start])) answer[i--] = nums[end]*nums[end--];
            else answer[i--] = nums[start]*nums[start++];
        }
        return answer;
    }
};