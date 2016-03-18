/** 231. Power of Two

Given an integer, write a function to determine if it is a power of two.

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        bool has = false;
        while (n) {
            if (n & 1) {
                if (!has) has = true;
                else return false;
            }
            n >>= 1;
        }
        return true;
    }
};

int main() {
    Solution s;
    ASSERT !s.isPowerOfTwo(0);
    ASSERT s.isPowerOfTwo(2);
    ASSERT !s.isPowerOfTwo(3);
    return 0;
}
