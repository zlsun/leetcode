/** 036. Valid Sudoku
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool validRow(const vector<vector<char>>& board, int r) {
        bool has[9] {false};
        for (int i = 0; i < 9; ++i) {
            char c = board[r][i];
            if (c == '.') continue;
            if (c < '1' || c > '9') return false;
            if (has[c - '1']) return false;
            has[c - '1'] = true;
        }
        return true;
    }
    bool validCol(const vector<vector<char>>& board, int l) {
        bool has[9] {false};
        for (int i = 0; i < 9; ++i) {
            char c = board[i][l];
            if (c == '.') continue;
            if (c < '1' || c > '9') return false;
            if (has[c - '1']) return false;
            has[c - '1'] = true;
        }
        return true;
    }
    bool validBox(const vector<vector<char>>& board, int x, int y) {
        bool has[9] {false};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char c = board[x + i][y + j];
                if (c == '.') continue;
                if (c < '1' || c > '9') return false;
                if (has[c - '1']) return false;
                has[c - '1'] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(const vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if (!validRow(board, i)) return false;
            if (!validCol(board, i)) return false;
            if (!validBox(board, i / 3 * 3, i % 3 * 3)) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    ASSERT s.isValidSudoku({
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    });
    ASSERT s.isValidSudoku({
        {'5', '3', '.', '.', '.', '.', '.', '.', '.'},
        {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    });
    ASSERT s.isValidSudoku({
        {'.', '8', '7', '6', '5', '4', '3', '2', '1'},
        {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'9', '.', '.', '.', '.', '.', '.', '.', '.'},
    });
    return 0;
}
