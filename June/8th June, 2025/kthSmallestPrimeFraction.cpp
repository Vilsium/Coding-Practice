// Leetcode question no 786

/*
You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
*/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float, pair<int, int>>> pq;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i+1; j < arr.size(); j++) {
                float fraction = (float) arr[i] / arr[j];
                pq.push({fraction, {arr[i], arr[j]}});
            }
        }
        vector<int> answer(2);
        // while(!pq.empty()) {
        //     cout << pq.top().first << " => " << pq.top().second.first << "/" << pq.top().second.second << endl;
        //     pq.pop();
        // }
        while(pq.size() > k) pq.pop();
        answer[0] = pq.top().second.first;
        answer[1] = pq.top().second.second;
        return answer;
    }
};