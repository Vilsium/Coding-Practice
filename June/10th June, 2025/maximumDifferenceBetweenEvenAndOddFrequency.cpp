// Leetcode question no 3442

/*
You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.

Return this maximum difference.
*/

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mpp;
        for(char c : s) {
            mpp[c]++;
        }
        int maxOddFreq = 0, minEvenFreq = INT_MAX;
        for(auto it : mpp) {
            if(it.second % 2 == 0) minEvenFreq = min(minEvenFreq, it.second);
            else maxOddFreq = max(maxOddFreq, it.second);
        }
        return maxOddFreq-minEvenFreq;
    }
};