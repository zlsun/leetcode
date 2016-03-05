/** 001. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,

return [0, 1].

UPDATE (2016/2/13):

The return format had been changed to zero-based indices. Please read the above updated description carefully.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, size_t> m;
        vector<int> v(2);
        for (size_t i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            int r = target - nums[i];
            if (m.find(r) != m.end() && m[r] != i) {
                v[0] = i;
                v[1] = m[r];
                if (v[0] > v[1]) swap(v[0], v[1]);
                break;
            }
        }
        return v;
    }
};

using vi = vector<int>;
int main() {
    Solution s;
    vi l {2, 7, 11, 15};
    ASSERT s.twoSum(l, 9) == vi{0, 1};
    l = {0, 4, 3, 0};
    ASSERT s.twoSum(l, 0) == vi{0, 3};
    l = {3, 2, 4};
    ASSERT s.twoSum(l, 6) == vi{1, 2};
    return 0;
}
