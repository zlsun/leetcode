/** 075. Sort Colors

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with an one-pass algorithm using only constant space?

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto p = nums.begin(), q = nums.begin();
        for (auto& i : nums) {
            if (i == 0) {
                if (p != q && &i != &*q) tie(*p, *q, i) = make_tuple(i, *p, *q);
                else if (&i != &*p) swap(*p, i);
                else if (&i != &*q) swap(*q, i);
                ++p;
                ++q;
            } else if (i == 1) {
                swap(*q, i);
                ++q;
            }
        }
    }
};

int main() {
    Solution s;
    Vi colors {0, 1, 2, 0, 1, 2};
    ASSERT (s.sortColors(colors), colors) == Vi {0, 0, 1, 1, 2, 2};
    ASSERT (s.sortColors(colors), colors) == Vi {0, 0, 1, 1, 2, 2};
    colors = {2, 1, 0};
    ASSERT (s.sortColors(colors), colors) == Vi {0, 1, 2};
    colors = {0, 1};
    ASSERT (s.sortColors(colors), colors) == Vi {0, 1};
    colors = {1, 0};
    ASSERT (s.sortColors(colors), colors) == Vi {0, 1};
    colors = {2, 0};
    ASSERT (s.sortColors(colors), colors) == Vi {0, 2};
    return 0;
}
