/** 010. Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) return true;
        if (!s.empty() && p.empty()) return false;
        char c = p[0];
        bool star = p.length() >= 2 && p[1] == '*';
        bool any = c == '.';
        if (star) {
            int t = 0;
            for (; t < s.length(); ++t) {
                if (any || s[t] == c) {
                    if (isMatch(s.substr(t), p.substr(2))) {
                        return true;
                    }
                } else {
                    break;
                }
            }
            return isMatch(s.substr(t), p.substr(2));
        } else {
            if (s.length() == 0) return false;
            return (any || s[0] == c) && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main() {
    Solution s;
    ASSERT !s.isMatch("aa","a");
    ASSERT s.isMatch("aa","aa");
    ASSERT !s.isMatch("aaa","aa");
    ASSERT s.isMatch("aa", "a*");
    ASSERT s.isMatch("aa", ".*");
    ASSERT s.isMatch("ab", ".*");
    ASSERT s.isMatch("aab", "c*a*b");
    ASSERT s.isMatch("a", "ab*");
    ASSERT !s.isMatch("a", ".*..a*");
    return 0;
}
