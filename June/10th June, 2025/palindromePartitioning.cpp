// Leetcode question no 131

/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
*/

class Solution {
    bool isPal(string s) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] != s[n - i - 1])
                return false;
            i++;
        }
        return true;
    }
    void solve(int i, int n, vector<string>& v, vector<vector<string>>& answer, string s) {
        if (i >= n) {
            answer.push_back(v);
            return;
        }
        for (int j = i; j < n; j++) {
            string st = s.substr(i, j - i + 1);
            if (isPal(st)){
                v.push_back(st);
                solve(j + 1, n, v, answer, s);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> v;
        int n = s.size();
        solve(0, n, v, answer, s);
        return answer;
    }
};