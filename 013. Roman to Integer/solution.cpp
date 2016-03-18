/** 013. Roman to Integer
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <map>
class Solution {
public:
    int romanToInt(string s) {
        map<char, string> sp {{'I', "VX"}, {'X', "LC"}, {'C', "DM"}};
        map<char, int> c2i {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int r = 0, i = 0, l = s.length();
        while (i < l) {
            char c = s[i];
            if (sp.find(c) != sp.end() && i + 1 < l && sp[c].find(s[i + 1]) != string::npos) {
                r += c2i[s[i + 1]] - c2i[c];
                ++i;
            } else {
                r += c2i[c];
            }
            ++i;
        }
        return r;
    }
};

int main() {
    Solution s;
    ASSERT s.romanToInt("II") == 2;
    return 0;
}
