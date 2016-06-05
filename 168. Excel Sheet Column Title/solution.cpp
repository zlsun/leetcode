/** 168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB

Credits:Special thanks to @ifanchu for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            if (n % 26) {
                s += 'A' + n % 26 - 1;
                n /= 26;
            } else {
                s += 'Z';
                n = n / 26 - 1;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution s;
    ASSERT s.convertToTitle(1) == "A";
    ASSERT s.convertToTitle(2) == "B";
    ASSERT s.convertToTitle(3) == "C";
    ASSERT s.convertToTitle(26) == "Z";
    ASSERT s.convertToTitle(27) == "AA";
    ASSERT s.convertToTitle(28) == "AB";
    ASSERT s.convertToTitle(52) == "AZ";
    ASSERT s.convertToTitle(53) == "BA";
    return 0;
}
