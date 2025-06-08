// Leetcode question no 506

/*
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int size = score.size();
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < size; i++) {
            pq.push({score[i], i});
        }
        vector<string> answer(size);
        int i = 0;
        while(!pq.empty()) {
            int qSize = pq.size();
            if(qSize == size) {
                answer[pq.top().second] = "Gold Medal";
                pq.pop();
            } else if(size - qSize == 1) {
                answer[pq.top().second] = "Silver Medal";
                pq.pop();
            } else if(size - qSize == 2) {
                answer[pq.top().second] = "Bronze Medal";
                pq.pop();
            } else {
                answer[pq.top().second] = to_string(size-qSize+1);
                pq.pop();
            }
        }
        return answer;
    }
};