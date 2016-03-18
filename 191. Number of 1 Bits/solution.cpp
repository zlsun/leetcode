/** 191. Number of 1 Bits
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

Credits:Special thanks to @ts for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int w = 0;
        while (n) {
            if (n & 1) ++w;
            n >>= 1;
        }
        return w;
    }
};

int main() {
    Solution s;
    ASSERT s.hammingWeight(11) == 3;
    return 0;
}
