/** 130. Surrounded Regions

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

**/

#include <iostream>
#include "../utils.h"
using namespace std;

using Board = vector<vector<char>>;
class Solution {
public:
    int m, n;
    void fill(Board& board, int i, int j, char o, char t) {
        board[i][j] = t;
        if (i > 1     && board[i - 1][j] == o) fill(board, i - 1, j, o, t);
        if (i < m - 1 && board[i + 1][j] == o) fill(board, i + 1, j, o, t);
        if (j > 1     && board[i][j - 1] == o) fill(board, i, j - 1, o, t);
        if (j < n - 1 && board[i][j + 1] == o) fill(board, i, j + 1, o, t);
    }
    void solve(Board& board) {
        m = board.size(), n = m ? board[0].size() : 0;
        if (m < 2 || n < 2) return;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') fill(board, i, 0, 'O', 'Y');
            if (board[i][n - 1] == 'O') fill(board, i, n - 1, 'O', 'Y');
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') fill(board, 0, j, 'O', 'Y');
            if (board[m - 1][j] == 'O') fill(board, m - 1, j, 'O', 'Y');
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};

int main() {
    Solution s;
    Board b {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    };
    s.solve(b);
    ASSERT b == Board {
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
    };
    return 0;
}
