/** 263. Ugly Number

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        int factor[] = {2, 3, 5};
        for (int i = 0; i < 3; ++i) {
            int f = factor[i];
            while (num % f == 0) num /= f;
        }
        return num == 1;
    }
};

int main() {
    Solution s;
    ASSERT !s.isUgly(0);
    ASSERT s.isUgly(6);
    ASSERT s.isUgly(8);
    ASSERT !s.isUgly(14);
    return 0;
}
