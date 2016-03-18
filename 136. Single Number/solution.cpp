/** 136. Single Number
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        int l = nums.size();
        int single = 0;
        for (int i = 0; i < l; ++i) {
            single ^= nums[i];
        }
        return single;
    }
};

int main() {
    Solution s;
    ASSERT s.singleNumber({1, 1, 2}) == 2;
    ASSERT s.singleNumber({1, 1, 3, 3, 2}) == 2;
    return 0;
}
