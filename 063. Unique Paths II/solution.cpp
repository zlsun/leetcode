/** 063. Unique Paths II
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = n ? obstacleGrid[0].size() : 0;
        vector<int> dp(m + 1);
        int v = 1;
        for (int j = 0; j < m; ++j) {
            if (!obstacleGrid[0][j]) {
                dp[j + 1] = v;
            } else {
                v = 0;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (!obstacleGrid[i][j - 1]) {
                    if (!obstacleGrid[i][j - 2])
                        dp[j] += dp[j - 1];
                } else {
                    dp[j] = 0;
                }
            }
        }
        return dp[m];
    }
};

int main() {
    Solution s;
    ASSERT s.uniquePathsWithObstacles({
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    }) == 2;
    return 0;
}
