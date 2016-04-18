/** 342. Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true.
Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

Credits:Special thanks to @yukuairoy  for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && !(num & 0xAAAAAAAA);
    }
};

int main() {
    Solution s;
    ASSERT s.isPowerOfFour(1);
    ASSERT s.isPowerOfFour(4);
    ASSERT !s.isPowerOfFour(5);
    ASSERT s.isPowerOfFour(16);
    return 0;
}
