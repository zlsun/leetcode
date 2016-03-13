/** 238. Product of Array Except Self

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        vector<int> v(l);
        int x = 1;
        for (int i = l - 1; i >= 0; --i) {
            int c = nums[i];
            v[i] = x;
            x *= c;
        }
        x = 1;
        for (int i = 0; i < l; ++i) {
            int c = nums[i];
            v[i] *= x;
            x *= c;
        }
        return v;
    }
};

int main() {
    Solution s;
    using vi = vector<int>;
    vi v {1, 2, 3, 4};
    ASSERT s.productExceptSelf(v) == vi{24,12,8,6};
    return 0;
}
