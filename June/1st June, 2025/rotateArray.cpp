// Leetcode Question no 189

/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

class Solution {
private:
    void rotateArray(vector<int> &nums, int start, int end) {
        while (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

public:
    void rotate(vector<int> &nums, int k) {
        if (k > 0) {
            int n = nums.size();
            k = k % n;
            rotateArray(nums, n - k, n - 1);
            rotateArray(nums, 0, n - k - 1);
            rotateArray(nums, 0, n - 1);
        }
    }
};