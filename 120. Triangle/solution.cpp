/** 120. Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int minimumTotal(const vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i) dp[i] = dp[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        return *min_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution s;
    ASSERT s.minimumTotal({
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    }) == 11;
    ASSERT s.minimumTotal({
        {-1},
        {2, 3},
        {1, -1, -3}
    }) == -1;
    return 0;
}
