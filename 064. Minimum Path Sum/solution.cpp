/** 064. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int minPathSum(const vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[1] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j - 1];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    ASSERT s.minPathSum(VVi {
        {1, 1, 1},
        {1, 2, 1},
    }) == 4;
    return 0;
}
