/** 012. Integer to Roman
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    string intToRoman(int i) {
        string s;
        s += string(i / 1000, 'M');
        i %= 1000;
        int m = 100;
        for (auto a : {"CDM", "XLC", "IVX"}) {
            char b = a[0], c = a[1], d = a[2];
            int n = i / m;
            if (n < 4) {
                s += string(n, b);
            } else if (n == 4) {
                s += b;
                s += c;
            } else if (n < 9) {
                s += c;
                s += string(n - 5, b);
            } else if (n == 9) {
                s += b;
                s += d;
            }
            i %= m;
            m /= 10;
        }
        return s;
    }
};

int main() {
    Solution s;
    ASSERT s.intToRoman(2) == "II";
    ASSERT s.intToRoman(9) == "IX";
    ASSERT s.intToRoman(10) == "X";
    ASSERT s.intToRoman(2000) == "MM";
    return 0;
}
