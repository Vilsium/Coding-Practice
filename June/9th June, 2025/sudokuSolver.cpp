// Leetcode question no 37

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

The '.' character indicates empty cells.
*/

class Solution {
private:
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char num = '1'; num <= '9'; num++) {
                        if(isValid(board, i, j, num)) {
                            board[i][j] = num;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num || board[row][i] == num) return false;
        }
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for(int i = startRow; i < startRow+3; i++) {
            for(int j = startCol; j < startCol+3; j++) {
                if(board[i][j] == num) return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};