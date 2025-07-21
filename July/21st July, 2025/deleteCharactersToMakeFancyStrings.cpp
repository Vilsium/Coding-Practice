// Leetcode question 1957

// A fancy string is a string where no three consecutive characters are equal.

// Given a string s, delete the minimum possible number of characters from s to make it fancy.

// Return the final string after the deletion. It can be shown that the answer will always be unique.

class Solution {
public:
    string makeFancyString(string s) {
        string answer = "";
        answer.push_back(s[0]);
        int count = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == answer.back()) {
                count++;
                if(count < 3) answer.push_back(s[i]);
            } else {
                count = 1;
                answer.push_back(s[i]);
            }
        }
        return answer;
    }
};