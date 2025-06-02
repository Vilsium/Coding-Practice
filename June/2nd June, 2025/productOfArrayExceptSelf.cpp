// Leetcode question no 238

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProd(nums.size());
        vector<int> suffixProd(nums.size());
        prefixProd[0] = 1;
        suffixProd[nums.size()-1] = 1;
        for(int i = 1; i < nums.size(); i++) {
            prefixProd[i] = prefixProd[i-1] * nums[i-1];
        }
        for(int i = nums.size()-2; i >= 0; i--) {
            suffixProd[i] = suffixProd[i+1] * nums[i+1];
        }
        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            result[i] = prefixProd[i] * suffixProd[i];
        }
        return result;
    }
};