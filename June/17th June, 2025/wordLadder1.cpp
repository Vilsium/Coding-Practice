// Leetcode question no 127

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        st.erase(beginWord);
        q.push({beginWord, 1});
        string wordAfterQ;
        while(!q.empty()) {
            string word = q.front().first;
            int seq = q.front().second;
            q.pop();
            if(word == endWord) return seq;
            for(int i = 0; i < word.length(); i++) {
                string temp = word;
                for(char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if(st.find(temp) != st.end()) {
                        q.push({temp, seq+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};