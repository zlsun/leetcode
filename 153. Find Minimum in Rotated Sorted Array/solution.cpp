/** 153. Find Minimum in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int findMin(const vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (r == 0) return nums[0];
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (nums[m] < nums[r]) r = m;
            else l = m;
        }
        return min(nums[l], nums[r]);
    }
};

int main() {
    Solution s;
    ASSERT s.findMin({4, 5, 6, 7, 0, 1, 2}) == 0;
    ASSERT s.findMin({1, 2, 3}) == 1;
    ASSERT s.findMin({2, 3, 1}) == 1;
    ASSERT s.findMin({5, 1, 2, 3, 4}) == 1;
    return 0;
}
