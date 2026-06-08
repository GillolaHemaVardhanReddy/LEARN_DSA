// LC 36 — Valid Sudoku  ·  MEDIUM  ·  SOLO (an L4 gate problem)
// Check if a 9x9 board is valid: no repeated digit in any row, column, or 3x3 box.
// '.' means empty. Only need to validate filled cells (not solvability).
// Paste ONLY the Solution class into LeetCode. main() is for local testing.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, int>> col, row, box;
        int n = board.size(), boxes = (board.size()/3) * (board[0].size()), box_current = 0;
        for(int i = 0 ; i < n ; i++ ) {
            int box_row = i/3;
            for(int j = 0; j < 9; j++ ) {
                if(board[i][j]=='.') continue;
                int box_num = box_row*3 + j/3;
                if(row[i].count(board[i][j]) || col[j].count(board[i][j]) || box[box_num].count(board[i][j])){
                    return false;
                }
                col[j][board[i][j]]++;
                row[i][board[i][j]]++;
                box[box_num][board[i][j]]++;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << sol.isValidSudoku(board) << "  (expect 1)\n";
    return 0;
}
