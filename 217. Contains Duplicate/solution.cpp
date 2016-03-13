/** 217. Contains Duplicate

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <algorithm>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int l = nums.size();
        if (l <= 1) return false;
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < l; ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}
