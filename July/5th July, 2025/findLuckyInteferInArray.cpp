// Leetcode question 1394

// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

// Return the largest lucky integer in the array. If there is no lucky integer return -1.

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(int i : arr) {
            mpp[i]++;
        }
        int answer = -1;
        for(auto it : mpp) {
            if(it.first == it.second) answer = max(answer, it.first);
        }
        return answer;
    }
};