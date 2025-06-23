// Leetcode question 417

/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/

class Solution {
private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        int m = heights.size();
        int n = heights[0].size();
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, -1, 0, 1};
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
            visited[row][col] = true;
            for(int i = 0; i < 4; i++) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];
                if(newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && !visited[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
                    q.push({newRow, newCol});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> answer;
        queue<pair<int, int>> q;
        vector<vector<bool>> pacificVisited(m, vector<bool> (n, false));
        vector<vector<bool>> atlanticVisited(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++) {
            q.push({i, 0});
        }
        for(int i = 0; i < n; i++) {
            q.push({0, i});
        }
        bfs(heights, q, pacificVisited);
        for(int i = 0; i < m; i++) {
            q.push({i, n-1});
        }
        for(int i = 0; i < n; i++) {
            q.push({m-1, i});
        }
        bfs(heights, q, atlanticVisited);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacificVisited[i][j] && atlanticVisited[i][j]) answer.push_back({i, j});
            }
        }
        return answer;
    }
};