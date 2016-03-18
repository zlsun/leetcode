/** 190. Reverse Bits
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

Credits:Special thanks to @ts for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = 0;
        for (int i = 0; i < 32; ++i) {
            r <<= 1;
            if (n & 1) r |= 1;
            n >>= 1;
        }
        return r;
    }
};

int main() {
    Solution s;
    ASSERT s.reverseBits(43261596) == 964176192;
    return 0;
}
