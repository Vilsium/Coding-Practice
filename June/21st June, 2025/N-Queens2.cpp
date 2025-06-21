// Leetcode question 52

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/

class Solution {
private:
    int answer = 0;
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
    void solve(vector<string>& board, int n, int row) {
        if(row == n) {
            answer++;
            return ;
        }
        for(int col = 0; col < n; col++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, n, row+1);
                board[row][col] = '.';
            }
        }

    }
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, n, 0);
        return answer;
    }
};