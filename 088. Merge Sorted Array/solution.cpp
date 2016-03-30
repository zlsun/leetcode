/** 088. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1, j = n - 1, k = m + n -1; j >= 0;) {
            nums1[k--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};

int main() {
    Solution s;
    vi a {1, 3, 5, 0, 0, 0}, b {2, 4, 6};
    s.merge(a, a.size() - b.size(), b, b.size());
    ASSERT a == vi {1, 2, 3, 4, 5, 6};
    return 0;
}
