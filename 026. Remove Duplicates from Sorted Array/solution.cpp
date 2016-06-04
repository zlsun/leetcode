/** 026. Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), j = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i-1] != nums[i]) {
                nums[j++] = nums[i];
            }
        }
        if (j < n) nums.erase(nums.begin() + j, nums.end());
        return j;
    }
};

int main() {
    Solution s;
    vi a;
    ASSERT s.removeDuplicates(a) == 0;
    a = {1, 1, 2};
    ASSERT s.removeDuplicates(a) == 2;
    ASSERT a == vi{1, 2};
    return 0;
}
