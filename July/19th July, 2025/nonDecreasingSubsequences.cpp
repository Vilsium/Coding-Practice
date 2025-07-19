// Leetcode question 491

// Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& answer, vector<int>& temp, int index, set<vector<int>>& st) {
        if(index >= nums.size()) {
            if(temp.size() >= 2 && !st.count(temp)) {
                answer.push_back(temp);
                st.insert(temp);
            }    
            return ;
        }
        if(temp.empty() || nums[index] >= temp.back()) {
            temp.push_back(nums[index]);
            solve(nums, answer, temp, index+1, st);
            temp.pop_back();
        }
        solve(nums, answer, temp, index+1, st);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> answer;
        if(nums.size() < 2) return answer;
        vector<int> temp;
        set<vector<int>> st;
        solve(nums, answer, temp, 0, st);
        return answer;
    }
};