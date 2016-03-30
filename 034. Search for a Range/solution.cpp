/** 034. Search for a Range
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        vector<int> res {
            lower_bound(nums, target),
            upper_bound(nums, target)
        };
        return res;
    }
    int lower_bound(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m;
            } else {
                r = m;
            }
        }
        return nums[l] == target ? l : (nums[r] == target ? r : -1);
    }
    int upper_bound(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) {
                r = m;
            } else {
                l = m;
            }
        }
        return nums[r] == target ? r : (nums[l] == target ? l : -1);
    }
};

int main() {
    Solution s;
    ASSERT s.searchRange({5, 7, 7, 8, 8, 10}, 8) == vi {3, 4};
    ASSERT s.searchRange({1}, 0) == vi {-1, -1};
    ASSERT s.searchRange({1}, 1) == vi {0, 0};
    return 0;
}
