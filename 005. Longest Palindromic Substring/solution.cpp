/** 005. Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

bool dp[1000][1000];
class Solution {
public:
    string longestPalindrome(const string& s) {
        int l = s.length();
        if (l <= 1) return s;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                if (i >= j) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
        int p, n = 0;
        for (int k = 0; k < l; ++k) {
            for (int i = 0; i + k < l; ++i) {
                int j = i + k;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                    if (dp[i][j] && k + 1 > n) {
                        p = i;
                        n = k + 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return s.substr(p, n);
    }
};

int main() {
    Solution s;
    ASSERT s.longestPalindrome("") == "";
    ASSERT s.longestPalindrome("a") == "a";
    ASSERT s.longestPalindrome("aa") == "aa";
    ASSERT s.longestPalindrome("aba") == "aba";
    ASSERT s.longestPalindrome("abab") == "aba";
    ASSERT s.longestPalindrome("cabab") == "aba";
    ASSERT s.longestPalindrome("babcbabcba") == "abcbabcba";
    ASSERT s.longestPalindrome("babcbabcbaccba") == "abcbabcba";
    return 0;
}
