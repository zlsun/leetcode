/** 067. Add Binary

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size(), lb = b.size();
        if (la < lb) return addBinary(b, a);
        int carry = 0;
        for (int i = la - 1; i >= 0; --i) {
            int j = lb - la + i;
            int y = j >= 0 ? b[j] - '0' : 0;
            int x = a[i] - '0';
            int s = x + y + carry;
            a[i] = s % 2 + '0';
            carry = s / 2;
        }
        if (carry) a = '1' + a;
        return a;
    }
};

int main() {
    Solution s;
    ASSERT s.addBinary("10", "10") == "100";
    ASSERT s.addBinary("1", "11") == "100";
    ASSERT s.addBinary("11", "1") == "100";
    ASSERT s.addBinary("11", "11") == "110";
    return 0;
}
