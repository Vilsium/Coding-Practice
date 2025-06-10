// Leetcode question no 216

/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/

class Solution {
    void solve(vector<vector<int>>& answer, vector<int>& subAnswer, int k, int n, int currSum, int noOfElems, int currNo) {
        if(currSum == n && noOfElems == k) {
            answer.push_back(subAnswer);
            return ;
        }
        else if(noOfElems == k && currSum != n) return ;
        else if(currSum > n || noOfElems > k || currNo > 9) return ;
        subAnswer.push_back(currNo);
        solve(answer, subAnswer, k, n, currSum+currNo, noOfElems+1, currNo+1);
        subAnswer.pop_back();
        solve(answer, subAnswer, k, n, currSum, noOfElems, currNo+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        vector<int> subAnswer;
        solve(answer, subAnswer, k, n, 0, 0, 1);
        return answer;
    }
};