/** 344. Reverse String
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        return {s.rbegin(), s.rend()};
    }
};

int main() {
    Solution s;
    ASSERT s.reverseString("") == "";
    ASSERT s.reverseString("1") == "1";
    ASSERT s.reverseString("123") == "321";
    return 0;
}
