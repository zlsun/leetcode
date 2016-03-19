/** 053. Maximum Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int m = INT_MIN, s = 0;
        for (auto i : nums) {
            s += i;
            m = max(m, s);
            if (s < 0) s = 0;
        }
        return m;
    }
};

int main() {
    Solution s;
    ASSERT s.maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) == 6;
    ASSERT s.maxSubArray({-2,-3}) == -2;
    return 0;
}
