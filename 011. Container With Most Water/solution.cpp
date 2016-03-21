/** 011. Container With Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int maxArea(const vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int m = 0;
        while (l < r) {
            int area = (r - l) * (height[l] < height[r] ? height[l++] : height[r--]);
            m = max(m, area);
        }
        return m;
    }
};

int main() {
    Solution s;
    ASSERT s.maxArea({1, 2, 4, 3}) == 4;
    ASSERT s.maxArea({1, 2, 3, 4}) == 4;
    ASSERT s.maxArea({1, 2}) == 1;
    return 0;
}
