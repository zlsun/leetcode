/** 198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int rob(const vector<int>& nums) {
        int l = nums.size();
        if (l == 0) return 0;
        vector<int> dp(l);
        dp[0] = nums[0];
        if (l >= 2) dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < l; ++i) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp[l - 1];
    }
};

int main() {
    Solution s;
    ASSERT s.rob({}) == 0;
    ASSERT s.rob({1}) == 1;
    ASSERT s.rob({1, 2}) == 2;
    ASSERT s.rob({1, 2, 3}) == 4;
    return 0;
}
