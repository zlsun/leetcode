/** 029. Divide Two Integers

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long m = labs(dividend), n = labs(divisor);
        int res = 0;
        while (m >= n) {
            long long t = n, count = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                count <<= 1;
            }
            m -= t;
            res += count;
        }
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        return sign * res;
    }
};

int main() {
    Solution s;
    ASSERT s.divide(16, 4) == 4;
    ASSERT s.divide(INT_MAX, 4) == INT_MAX / 4;
    ASSERT s.divide(INT_MIN, -1) == INT_MAX;
    ASSERT s.divide(INT_MAX, -1) == -INT_MAX;
    return 0;
}
