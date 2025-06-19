// Leetcode question 1631

/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> distance(rows, vector<int> (cols, INT_MAX));
        distance[0][0] = 0;
        pq.push({0, {0, 0}});
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == rows-1 && col == cols-1) return effort;
            for(int i = 0; i < 4; i++) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];
                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int newEffort = max(effort, abs(heights[newRow][newCol] - heights[row][col]));
                    if(newEffort < distance[newRow][newCol]) {
                        distance[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }
};