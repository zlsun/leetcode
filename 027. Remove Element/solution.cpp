/** 027. Remove Element

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& v, int x) {
        int l = v.size();
        int idx = 0;
        for (int i = 0; i < l; ++i) {
            if (v[i] != x) {
                if (idx != i) v[idx] = v[i];
                ++idx;
            }
        }
        return idx;
    }
};

int main() {
    Solution s;
    using vi = vector<int>;
    vi v {0, 1, 0, 3, 12};
    ASSERT s.removeElement(v, 0) == 3;
    ASSERT v == vi{1, 3, 12, 3, 12};
    v = {3, 3};
    ASSERT s.removeElement(v, 5) == 2;
    ASSERT v == vi{3, 3};
    ASSERT s.removeElement(v, 3) == 0;
    ASSERT v == vi{3, 3};
    return 0;
}
