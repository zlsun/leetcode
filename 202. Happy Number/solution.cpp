/** 202. Happy Number
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

Credits:Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <map>
class Solution {
public:
    int sqsum(int n) {
        int r = 0;
        while (n) {
            int m = n % 10;
            r += m * m;
            n /= 10;
        }
        return r;
    }
    bool isHappy(int n) {
        static std::map<int, int> cache;
        if (cache.find(n) != cache.end()) {
            if (cache[n] == -1) cache[n] = 0;
            return cache[n];
        }
        if (n <= 0) return cache[n] = 0;
        if (n == 1) return cache[n] = 1;
        cache[n] = -1;
        return cache[n] = isHappy(sqsum(n));
    }
};

int main() {
    Solution s;
    ASSERT s.isHappy(19);
    ASSERT !s.isHappy(2);
    ASSERT s.isHappy(10);
    return 0;
}
