/** 343. Integer Break

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.

  There is a simple O(n) solution to this problem.
  You may check the breaking results of n ranging from 7 to 10 to discover the regularities.

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int res = 1;
        while (n > 6) {
            n -= 3;
            res *= 3;
        }
        return res * (n - n / 2) * (n / 2);
    }
};

int main() {
    Solution s;
    ASSERT s.integerBreak(2) == 1;
    ASSERT s.integerBreak(5) == 6;
    ASSERT s.integerBreak(6) == 9;
    ASSERT s.integerBreak(7) == 12;
    ASSERT s.integerBreak(8) == 18;
    ASSERT s.integerBreak(9) == 27;
    ASSERT s.integerBreak(10) == 36;
    return 0;
}
