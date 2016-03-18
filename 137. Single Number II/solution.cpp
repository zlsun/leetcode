/** 137. Single Number II

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int singleNumber(const vector<int>& A) {
        int l = A.size();
        int ones = 0, twos = 0, xthrees = 0;
        for (int i = 0; i < l; ++i) {
            twos |= (ones & A[i]);
            ones ^= A[i];
            xthrees = ~(ones & twos);
            ones &= xthrees;
            twos &= xthrees;
        }
        return ones;
    }
};

int main() {
    Solution s;
    ASSERT s.singleNumber({1, 1, 1, 2, 3, 3, 3}) == 2;
    return 0;
}
