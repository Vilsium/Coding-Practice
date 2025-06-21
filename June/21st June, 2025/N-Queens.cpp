// Leetcode question 51

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        for(int j = 0; j < n; j++) {
            if(board[row][j] == 'Q') return false;
        }
        for(int i = 0; i < n; i++) {
            if(board[i][col] == 'Q') return false;
        }
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(vector<string>& board, int n, vector<vector<string>>& answer, int row) {
        if(row == n) {
            answer.push_back({board});
            return ;
        }
        for(int col = 0; col < n; col++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, n, answer, row+1);
                board[row][col] = '.';
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> answer;
        solve(board, n, answer, 0);
        return answer;
    }
};