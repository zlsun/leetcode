/** 096. Unique Binary Search Trees
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int k = 1; k <= i; ++k) {
                dp[i] += dp[k - 1] * dp[i - k];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    ASSERT s.numTrees(3) == 5;
    return 0;
}
