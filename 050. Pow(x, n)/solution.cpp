/** 050. Pow(x, n)
Implement pow(x, n).

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool neg = n < 0;
        long long ln = neg ? -(long long)n : n;
        double res = 1;
        while (ln) {
            if (ln & 1) res *= x;
            x *= x;
            ln >>= 1;
        }
        return neg ? 1 / res : res;
    }
};

int main() {
    Solution s;
    ASSERT s.myPow(2, 3) == 8;
    ASSERT s.myPow(2, 10) == 1024;
    ASSERT s.myPow(2, -1) == 0.5;
    ASSERT s.myPow(1, -2147483648) == 1;
    return 0;
}
