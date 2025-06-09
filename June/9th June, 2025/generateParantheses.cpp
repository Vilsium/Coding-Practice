// Leetcode question no 22

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

class Solution {
private:
    void solve(int open, int close, string s, vector<string>& answer) {
        if(open == 0 && close == 0) {
            answer.push_back(s);
            return ;
        }
        if(open == close) solve(open-1, close, s+"(", answer);
        else if(open == 0) solve(open, close-1, s+")", answer);
        else {
            solve(open-1, close, s+"(", answer);
            solve(open, close-1, s+")", answer);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        int open = n, close = n;
        solve(open, close, "", answer);
        return answer;
    }
};