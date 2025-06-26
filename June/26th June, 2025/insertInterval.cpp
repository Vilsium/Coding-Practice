// Leetcode question 57

/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> answer;
        bool flag = false;
        int startingPoint = newInterval[0];
        int endingPoint = newInterval[1];
        if(n == 0) {
            answer.push_back(newInterval);
            return answer;
        }
        for(int i = 0; i < n; i++) {
            if(flag) answer.push_back(intervals[i]);
            else if(intervals[i][1] < newInterval[0]) answer.push_back(intervals[i]);
            else if(endingPoint >= intervals[i][0] || endingPoint == INT_MIN) {
                startingPoint = min(startingPoint, intervals[i][0]);
                endingPoint = max(endingPoint, intervals[i][1]);
            } else {
                answer.push_back({startingPoint, endingPoint});
                answer.push_back(intervals[i]);
                flag = true;
            }
        }
        if(!flag) answer.push_back({startingPoint, endingPoint});
        return answer;
    }
};