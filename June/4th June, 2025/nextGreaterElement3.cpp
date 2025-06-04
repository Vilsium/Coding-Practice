// Leetcode question no 556

/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        string original = s;
        int right1 = s.size() - 2;
        while (right1 >= 0 && s[right1] >= s[right1 + 1]) {
            right1--; 
        }
        if (right1 == -1) {
            return -1;
        }
        int right2 = s.size() - 1;
        while (s[right2] <= s[right1]) {
            right2--;
        }
        swap(s[right1], s[right2]);
        reverse(s.begin() + right1 + 1, s.end());
        long long answer = stoll(s);
        long long originalNum = stoll(original);
        if (answer > INT_MAX || answer <= originalNum) {
            return -1;
        }
        return (int)answer;
    }
};