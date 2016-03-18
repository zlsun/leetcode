/** 213. House Robber II
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int rob(const vector<int>& nums) {
        int l = nums.size();
        if (l == 0) return 0;
        if (l == 1) return nums[0];
        vector<int> dp1(l - 1);
        vector<int> dp2(l - 1);
        {
            vector<int>& dp = dp1;
            dp[0] = nums[0];
            if (l >= 2) dp[1] = max(nums[0], nums[1]);
            for (int i = 2; i < l - 1; ++i) {
                dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
            }
        }
        {
            vector<int>& dp = dp2;
            dp[0] = nums[1];
            if (l >= 2) dp[1] = max(nums[1], nums[2]);
            for (int i = 2; i < l - 1; ++i) {
                dp[i] = max(dp[i - 1], nums[i + 1] + dp[i - 2]);
            }
        }
        return max(dp1[l - 2], dp2[l - 2]);
    }
};

int main() {
    Solution s;
    ASSERT s.rob({}) == 0;
    ASSERT s.rob({1}) == 0;
    ASSERT s.rob({1, 2, 3}) == 3;
    ASSERT s.rob({1, 2, 3, 4}) == 6;
    return 0;
}
