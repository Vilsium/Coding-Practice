// Leetcode question no 39

/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

class Solution {
private:
    void solve(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& subAnswer, int index, int currSum, int target) {
        if(currSum == target) {
            answer.push_back(subAnswer);
            return ;
        }
        else if(currSum > target || index >= candidates.size()) return ;
        subAnswer.push_back(candidates[index]);
        solve(candidates, answer, subAnswer, index, currSum+candidates[index], target);
        subAnswer.pop_back();
        solve(candidates, answer, subAnswer, index+1, currSum, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> subAnswer;
        solve(candidates, answer, subAnswer, 0, 0, target);
        return answer;
    }
};