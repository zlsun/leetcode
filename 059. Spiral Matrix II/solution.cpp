/** 059. Spiral Matrix II
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if (n == 0) return res;
        int i = 0, j = 0;
        int di = 0, dj = 1;
        int x = 1;
        while (x <= n * n) {
            res[i][j] = x++;
            if (i + di < 0 || i + di >= n || j + dj < 0 || j + dj >= n || res[i + di][j + dj]) {
                swap(di, dj);
                dj = -dj;
            }
            i += di;
            j += dj;
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.generateMatrix(0) == vvi{};
    ASSERT s.generateMatrix(1) == vvi{{1}};
    ASSERT s.generateMatrix(3) == vvi{
        { 1, 2, 3 },
        { 8, 9, 4 },
        { 7, 6, 5 }
    };
    return 0;
}
