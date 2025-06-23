// Leetcode question 419

/*
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
*/

class Solution {
private:
    void dfs(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& visited) {
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '.' || visited[row][col]) return ;
        visited[row][col] = true;
        dfs(board, row+1, col, visited);
        dfs(board, row-1, col, visited);
        dfs(board, row, col+1, visited);
        dfs(board, row, col-1, visited);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int answer = 0;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X' && !visited[i][j]) {
                    answer++;
                    dfs(board, i, j, visited);
                }
            }
        }
        return answer;
    }
};