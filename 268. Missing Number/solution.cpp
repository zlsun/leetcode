/** 268. Missing Number

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <algorithm>
class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        int l = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return (1 + l) * l / 2 - sum;
    }
};

int main() {
    Solution s;
    ASSERT s.missingNumber({0, 1, 3}) == 2;
    ASSERT s.missingNumber({0, 1, 2}) == 3;
    return 0;
}
