/** 031. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;
        i = j = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1]) --i;
        if (i == 0) return reverse(nums.begin(), nums.end());
        while (nums[j] <= nums[i - 1]) --j;
        swap(nums[j], nums[i - 1]);
        reverse(nums.begin() + i, nums.end());
    }
};

int main() {
    Solution s;
    vi v {1, 2, 3};
    s.nextPermutation(v);
    ASSERT v == vi{1, 3, 2};
    s.nextPermutation(v);
    ASSERT v == vi{2, 1, 3};
    s.nextPermutation(v);
    ASSERT v == vi{2, 3, 1};
    return 0;
}
