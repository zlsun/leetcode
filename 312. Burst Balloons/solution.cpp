/** 312. Burst Balloons

    Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
    number on it represented by array nums.

    You are asked to burst all the balloons. If the you burst
    balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left
    and right are adjacent indices of i. After the burst, the left and right
    then becomes adjacent.

    Find the maximum coins you can collect by bursting the balloons wisely.

    Note:
    (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
    (2) 0 <= n <= 500, 0 <= nums[i] <= 100

    Example:

    Given [3, 1, 5, 8]

    Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 1; l < n - 1; ++l) {
            for (int b = 0; b < n - l - 1; ++b) {
                int e = b + l + 1;
                for (int k = b + 1; k < e; ++k) {
                    dp[b][e] = max(dp[b][e], dp[b][k] + nums[b] * nums[k] * nums[e] + dp[k][e]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution s;
    vector<int> v {3, 1, 5, 8};
    ASSERT s.maxCoins(v) == 167;
    return 0;
}
