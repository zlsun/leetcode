/** 264. Ugly Number II

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

  The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
  An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
  The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
  Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        static int i = 0, j = 0, k = 0;
        static vector<int> uglys(1, 1);
        while ((int)uglys.size() < n) {
            int m = min(min(uglys[i] * 2, uglys[j] * 3), uglys[k] * 5);
            if (m == uglys[i] * 2) ++i;
            if (m == uglys[j] * 3) ++j;
            if (m == uglys[k] * 5) ++k;
            uglys.push_back(m);
        }
        return uglys[n - 1];
    }
};

int main() {
    Solution s;
    ASSERT s.nthUglyNumber(10) == 12;
    return 0;
}
