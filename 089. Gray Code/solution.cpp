/** 089. Gray Code
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int>{0};
        if (n == 1) return vector<int>{0, 1};
        vector<int> pre = grayCode(n - 1);
        vector<int> res;
        for (auto it = pre.begin(); it != pre.end(); ++it) {
            res.push_back(*it);
        }
        int p = 1 << (n - 1);
        for (auto it = pre.rbegin(); it != pre.rend(); ++it) {
            res.push_back(p + *it);
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.grayCode(2) == vector<int>{0b00, 0b01, 0b11, 0b10};
    return 0;
}
