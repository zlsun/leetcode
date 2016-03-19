/** 070. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 1;
        while (--n) {
            int tmp = a;
            a = b;
            b += tmp;
        }
        return b;
    }
};

int main() {
    Solution s;
    ASSERT s.climbStairs(1) == 1;
    ASSERT s.climbStairs(2) == 2;
    ASSERT s.climbStairs(3) == 3;
    return 0;
}
