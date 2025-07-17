// Leetcode question 438

// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        if(s.length() < p.length()) return answer;
        vector<int> pFreq(26, 0), sFreq(26, 0);
        int pLen = p.length();
        for(int i = 0; i < pLen; i++) {
            pFreq[p[i]-'a']++;
            sFreq[s[i]-'a']++;
        }
        if(sFreq == pFreq) answer.push_back(0);
        for(int i = pLen; i < s.length(); i++) {
            sFreq[s[i]-'a']++;
            sFreq[s[i-pLen]-'a']--;
            if(sFreq == pFreq) answer.push_back(i-pLen+1);
        }
        return answer;
    }
};