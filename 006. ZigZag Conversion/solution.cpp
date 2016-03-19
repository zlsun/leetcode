/** 006. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <algorithm>
#include <iterator>
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= (size_t)numRows) return s;
        vector<vector<char>> z(numRows);
        int r = 0, d = 1;
        for (char c : s) {
            z[r].push_back(c);
            if (r == 0) d = 1;
            else if (r == numRows - 1) d = -1;
            r += d;
        }
        string res;
        for (auto& v : z) {
            copy(v.begin(), v.end(), back_inserter(res));
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR";
    return 0;
}
