// Leetcode question 1695

// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

// Return the maximum score you can get by erasing exactly one subarray.

// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int left = 0;
        int currSum = 0;
        int maxSum = 0;
        for(int right = 0; right < nums.size(); right++) {
            while(st.find(nums[right]) != st.end()) {
                currSum -= nums[left];
                st.erase(nums[left]);
                left++;
            }
            currSum += nums[right];
            st.insert(nums[right]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};