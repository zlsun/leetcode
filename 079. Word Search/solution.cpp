/** 079. Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = m ? board[0].size() : 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (bt(board, word, i, j)) return true;
                }
            }
        }
        return false;
    }
    bool bt(vector<vector<char>>& board, string word, int i, int j) {
        if (word.length() == 0) return true;
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (board[i][j] != word[0]) return false;
        for (auto d : vector<vector<int>> {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}) {
            board[i][j] = ' ';
            if (bt(board, word.substr(1), i + d[0], j + d[1])) {
                board[i][j] = word[0];
                return true;
            }
            board[i][j] = word[0];
        }
        return false;
    }
};

int main() {
    Solution s;
    vv<char> b = {
      {'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}
    };
    ASSERT s.exist(b, "ABCCED");
    ASSERT s.exist(b, "SEE");
    ASSERT !s.exist(b, "ABCB");
    return 0;
}
