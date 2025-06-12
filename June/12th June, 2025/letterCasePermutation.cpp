// Leetcode question no 784

/*
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.
*/

class Solution {
    void solve(string s, int index, string temp, vector<string>& answer) {
        if(temp.length() == s.length()) {
            answer.push_back(temp);
            return ;
        }
        if(index >= s.length()) return ;
        if(isdigit(s[index])) solve(s, index+1, temp+s[index], answer);
        else {
            if(islower(s[index])) {
                s[index] -= 32;
                solve(s, index+1, temp+s[index], answer);
                s[index] += 32;
                solve(s, index+1, temp+s[index], answer);
            } else {
                s[index] += 32;
                solve(s, index+1, temp+s[index], answer);
                s[index] -= 32;
                solve(s, index+1, temp+s[index], answer);
            }
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> answer;
        solve(s, 0, "", answer);
        return answer;
    }
};