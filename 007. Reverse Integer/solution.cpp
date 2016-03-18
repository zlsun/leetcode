/** 007. Reverse Integer
Reverse digits of an integer.

Example1: x =  123, return  321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <cstdint>
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool neg = x < 0;
        x = neg ? -x : x;
        int r = 0;
        while (x) {
            if (r > INT_MAX / 10) return 0;
            r *= 10;
            r += x % 10;
            x /= 10;
        }
        return neg ? -r : r;
    }
};

int main() {
    Solution s;
    ASSERT s.reverse(123) == 321;
    ASSERT s.reverse(-123) == -321;
    ASSERT s.reverse(1534236469) == 0;
    ASSERT s.reverse(-2147483648) == 0;
    return 0;
}
