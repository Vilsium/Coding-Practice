// Leetcode question 93

/*
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
*/

class Solution {
private:
    bool isSafe(string s) {
        int n = s.length();
        if(n == 1) return true;
        if(s[0] == '0' || n > 3) return false;
        return (0 <= stoi(s) && stoi(s) < 256);
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        int n = s.length();
        if(n < 4 || n > 12) return answer;
        for(int i = 1; i < 4; i++) {
            for(int j = 1; j < 4; j++) {
                for(int k = 1; k < 4; k++) {
                    if(i + j + k < n && i + j + k + 3 >= n) {
                        string a = s.substr(0, i);
                        string b = s.substr(i, j);
                        string c = s.substr(i+j, k);
                        string d = s.substr(i+j+k);
                        if(isSafe(a) && isSafe(b) && isSafe(c) && isSafe(d)) answer.push_back(a + "." + b + "." + c + "." + d);
                    }
                }
            }
        }
        return answer;
    }
};