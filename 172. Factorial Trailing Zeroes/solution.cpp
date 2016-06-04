/** 172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:Special thanks to @ts for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

int main() {
    Solution s;
    ASSERT s.trailingZeroes(10) == 2;
    ASSERT s.trailingZeroes(100) == 24;
    return 0;
}
