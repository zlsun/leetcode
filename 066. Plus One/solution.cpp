/** 066. Plus One
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> plusOne(const vector<int>& digits) {
        vector<int> res(digits);
        int l = digits.size();
        int inc = 1;
        for (int i = l - 1; inc && i >= 0; --i) {
            res[i] += inc;
            inc = res[i] / 10;
            res[i] %= 10;
        }
        if (inc) res.insert(res.begin(), inc);
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.plusOne({9}) == vi{1, 0};
    return 0;
}
