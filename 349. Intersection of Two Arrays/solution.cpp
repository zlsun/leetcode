/** 349. Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

Each element in the result must be unique.
The result can be in any order.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> v;
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(v));
        return v;
    }
};

int main() {
    Solution s;
    ASSERT s.intersection(vi{1, 2, 2, 1}, vi{2, 2}) == vi{2};
    return 0;
}
