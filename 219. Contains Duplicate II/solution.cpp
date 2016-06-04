/** 219. Contains Duplicate II

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        unordered_set<int> recent;
        for (int i = 0; i < nums.size(); ++i) {
            if (recent.find(nums[i]) != recent.end()) return true;
            recent.emplace(nums[i]);
            if (recent.size() > k) recent.erase(recent.find(nums[i-k]));
        }
        return false;
    }
};

int main() {
    Solution s;
    ASSERT !s.containsNearbyDuplicate(vi{1, 2, 1}, 1);
    ASSERT s.containsNearbyDuplicate(vi{1, 2, 1}, 2);
    return 0;
}
