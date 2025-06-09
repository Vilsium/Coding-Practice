// Leetcode question no 77

/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
*/

class Solution {
private:
    void solve(int currNum, int n, int k, vector<int>& combi, vector<vector<int>>& answer) {
        if(combi.size() == k) {
            answer.push_back(combi);
            return ;
        }
        for(int i = currNum; i <= n; i++) {
            combi.push_back(i);
            solve(i+1, n, k, combi, answer);
            combi.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> combi;
        solve(1, n, k, combi, answer);
        return answer;
    }
};