/** 169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than &lfloor; n/2 &rfloor; times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:Special thanks to @ts for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int majorityElement(const vector<int>& nums) {
        int l = nums.size();
        int cnt = 0, major;
        for (int i = 0; i < l; ++i) {
            if (cnt == 0) {
                major = nums[i];
                ++cnt;
            } else {
                cnt += major == nums[i] ? 1 : -1;
            }
        }
        return major;
    }
};

int main() {
    Solution s;
    ASSERT s.majorityElement({1, 1, 3}) == 1;
    return 0;
}
