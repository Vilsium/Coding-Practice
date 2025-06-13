// Leetcode question no 3211

/*
You are given a positive integer n.

A binary string x is valid if all substrings of x of length 2 contain at least one "1".

Return all valid strings with length n, in any order.
*/

class Solution {
    void solve(vector<string>& answer, int n, string s, int index) {
        if(s.length() == n) {
            answer.push_back(s);
            return ;
        }
        if(s[index] == '0') solve(answer, n, s+"1", index+1);
        else {
            solve(answer, n, s+"1", index+1);
            solve(answer, n, s+"0", index+1);
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> answer;
        solve(answer, n, "0", 0);
        solve(answer, n, "1", 0);
        return answer;
    }
};