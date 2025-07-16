// Leetcode question 30

// You are given a string s and an array of strings words. All the strings of words are of the same length.

// A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

// For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
// Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        if(s.empty() || words.empty()) return answer;
        int wordLength = words[0].length();
        int size = words.size();
        int totalLength = size * wordLength;
        unordered_map<string, int> mpp;
        for(string word : words) {
            mpp[word]++;
        }
        for(int i = 0; i < wordLength; i++) {
            int left = i, right = i;
            unordered_map<string, int> seen;
            int count = 0;
            while(right + wordLength <= s.length()) {
                string word = s.substr(right, wordLength);
                right += wordLength;
                if(mpp.find(word) != mpp.end()) {
                    seen[word]++;
                    count++;
                    while(seen[word] > mpp[word]) {
                        string leftWord = s.substr(left, wordLength);
                        left += wordLength;
                        seen[leftWord]--;
                        count--;
                    }
                    if(count == size) answer.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return answer;
    }
};