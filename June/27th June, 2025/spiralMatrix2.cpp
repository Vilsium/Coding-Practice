// Leetcode question 59

/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer(n , vector<int>(n));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int count = 0;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j) answer[top][j] = ++count;
            ++top;
            for (int i = top; i <= bottom; ++i) answer[i][right] = ++count;
            --right;
            if (top <= bottom) {
                for (int j = right; j >= left; --j) answer[bottom][j] = ++count;
                --bottom;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; --i) answer[i][left] = ++count;
                ++left;
            }
        }
        return answer;
    }
};