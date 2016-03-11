/** 283. Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums  = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int l = v.size();
        int i = 0;
        for (int j = 0; j < l; ++j) {
            if (v[j] != 0) {
                if (i != j) swap(v[i], v[j]);
                ++i;
            }
        }
    }
};

int main() {
    Solution s;
    using vi = vector<int>;
    vi v {0, 1, 0, 3, 12};
    s.moveZeroes(v);
    ASSERT v == vi{1, 3, 12, 0, 0};
    return 0;
}
