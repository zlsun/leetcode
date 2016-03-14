/** 069. Sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <cmath>
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double res = (double)x / 2, last = x;
        while (std::abs(res - last) > 0.4) {
            last = res;
            res = (res + x / res) / 2;
        }
        return (int)res;
    }
};

int main() {
    Solution s;
    ASSERT s.mySqrt(1) == 1;
    ASSERT s.mySqrt(16) == 4;
    ASSERT s.mySqrt(10) == 3;
    return 0;
}
