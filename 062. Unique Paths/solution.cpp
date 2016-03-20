/** 062. Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int nCr(int n, int r) {
        long res = 1;
        for (int i = 1; i <= r; ++i) {
            res *= n - r + i;
            res /= i;
        }
        return res;
    }
    int uniquePaths(int m, int n) {
        return nCr(m + n - 2, min(m, n) - 1);
    }
};

int main() {
    Solution s;
    ASSERT s.uniquePaths(2, 2) == 2;
    return 0;
}
