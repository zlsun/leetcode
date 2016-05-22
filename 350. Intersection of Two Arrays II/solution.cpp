/** 350. Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to num2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& s1, vector<int>& s2) {
        vector<int> v;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(v));
        return v;
    }
};

int main() {
    Solution s;
    vi v1, v2;
    v1 = {1, 2, 2, 1};
    v2 = {2, 2};
    ASSERT s.intersect(v1, v2) == vi{2, 2};
    v1 = {2, 1};
    v2 = {1, 1};
    ASSERT s.intersect(v1, v2) == vi{1};
    return 0;
}
