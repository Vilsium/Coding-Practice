// Leetcode question 2200

/*
You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.

Return a list of all k-distant indices sorted in increasing order.
*/

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        const int n=nums.size();
        vector<int> answer;
        for(int i=0, j=0; i<n; i++){
            if (nums[i]==key){
                int up=min(n-1, i+k);
                for( j=max(j, i-k); j<=up; j++)
                    answer.push_back(j);
            }
        }
        return answer;
    }
};