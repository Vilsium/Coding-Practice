// Leetcode question no 1091

/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1 && grid[0][0] == 0) return 1;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> distance(n, vector<int> (n, INT_MAX));
        distance[0][0] = 1;
        q.push({1, {0, 0}});
        int deltaRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int deltaCol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int distFrmSrc = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for(int i = 0; i < 8; i++) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0 && distFrmSrc + 1 < distance[newRow][newCol]) {
                    if(newRow == n-1 && newCol == n-1) return distFrmSrc+1;
                    distance[newRow][newCol] = distFrmSrc + 1;
                    q.push({distFrmSrc+1, {newRow, newCol}});
                }
            }
        }
        return -1;
    }
};