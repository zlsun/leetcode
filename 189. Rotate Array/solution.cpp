/** 189. Rotate Array
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]
Hint:
Could you do it in-place with O(1) extra space?

Related problem: Reverse Words in a String II

Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    void rotate(vector<int>& v, int k) {
        if (v.size() == 0 || k % v.size() == 0) return;
        k %= v.size();
        reverse(v.begin(), v.end());
        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
    }
};

int main() {
    Solution s;
    vi a;
    s.rotate(a, 3);
    ASSERT a == vi{};
    a = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(a, 0);
    ASSERT a == vi{1, 2, 3, 4, 5, 6, 7};
    s.rotate(a, 3);
    ASSERT a == vi{5, 6, 7, 1, 2, 3, 4};
    return 0;
}
