/** 051. N-Queens
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
private:
    vector<vector<string>> sols;
    vector<string> sol;
    int fullrow;
public:
    vector<vector<string>> solveNQueens(int n) {
        sols.clear();
        sol = vector<string>(n, string(n, '.'));
        fullrow = (1 << n) - 1;
        search(0, 0, 0, 0);
        return sols;
    }
    void search(int idx, int row, int ld, int rd) {
        int pos, p;
        if (row == fullrow) {
            sols.push_back(sol);
        } else {
            pos = fullrow & (~(row | ld | rd));
            while (pos) {
                p = pos & -pos;
                pos -= p;
                set(idx, p, 'Q');
                search(idx + 1, row | p, (ld | p) << 1, (rd | p) >> 1);
                set(idx, p, '.');
            }
        }
    }
    void set(int idx, int p, char val) {
        int col = 0;
        while (!(p & 1)) {
            p >>= 1;
            ++col;
        }
        sol[idx][col] = val;
    }
};

int main() {
    Solution s;
    zlog s.solveNQueens(4);
    return 0;
}
