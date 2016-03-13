/** 260. Single Number III

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo = 0;
        int l = nums.size();
        for (int i = 0; i < l; ++i)
            xo ^= nums[i];
        int r = xo & ~(xo - 1);
        int a = 0, b = 0;
        for (int i = 0; i < l; ++i)
            if (nums[i] & r) a ^= nums[i];
            else b ^= nums[i];
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};

int main() {
    Solution s;
    using vi = vector<int>;
    vi v {1, 2, 1, 3, 2, 5};
    ASSERT s.singleNumber(v) == vi{3, 5};
    return 0;
}
