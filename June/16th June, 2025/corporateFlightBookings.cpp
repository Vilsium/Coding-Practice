// Leetcode question no 1109

/*
There are n flights that are labeled from 1 to n.

You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n+1, 0);
        for(auto booking : bookings) {
            answer[booking[0]-1] += booking[2];
            answer[booking[1]] -= booking[2];
        }
        for(int i = 1; i < n; i++) {
            answer[i] += answer[i-1];
        }
        answer.pop_back();
        return answer;
    }
};