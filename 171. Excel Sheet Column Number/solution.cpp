/** 171. Excel Sheet Column Number
Related to question Excel Sheet Column Title
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28

Credits:Special thanks to @ts for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int v = 0;
        int l = s.length();
        for (int i = 0; i < l; ++i) {
            v *= 26;
            v += s[i] - 'A' + 1;
        }
        return v;
    }
};

int main() {
    Solution s;
    ASSERT s.titleToNumber("A") == 1;
    ASSERT s.titleToNumber("Z") == 26;
    ASSERT s.titleToNumber("AB") == 28;
    return 0;
}
