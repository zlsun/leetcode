/** 287. Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        int slow = 0, fast = 0, find = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        do {
            find = nums[find];
            slow = nums[slow];
        } while (slow != find);
        return find;
    }
};

int main() {
    Solution s;
    ASSERT s.findDuplicate({1, 2, 2, 3, 4}) == 2;
    return 0;
}
