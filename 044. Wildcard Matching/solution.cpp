/** 044. Wildcard Matching
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length(), lp = p.length();
        vector<bool> res(lp + 1);
        res[0] = true;
        for (int i = 1; i <= lp; ++i) {
            if (p[i-1] == '*')
                res[i] = res[i-1];
        }
        for (int i = 1; i <= ls; ++i) {
            bool pre = res[0];
            res[0] = false;
            for (int j = 1; j <= lp; ++j) {
                bool next = res[j];
                if (p[j-1] != '*') {
                    res[j] = (s[i-1] == p[j-1] || p[j-1] == '?') && pre;
                } else {
                    res[j] = res[j] || res[j-1];
                }
                pre = next;
            }
        }
        return res[lp];
    }
};

int main() {
    Solution s;
    ASSERT !s.isMatch("aa","a");
    ASSERT s.isMatch("aa","aa");
    ASSERT !s.isMatch("aaa","aa");
    ASSERT s.isMatch("aa", "*");
    ASSERT s.isMatch("aa", "a*");
    ASSERT s.isMatch("ab", "?*");
    ASSERT !s.isMatch("aab", "c*a*b");
    ASSERT s.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaab", "a*******b");
    return 0;
}
