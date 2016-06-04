/** 205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s2t[256] = {0}, t2s[256] = {0};
        for (int i = 0; i < s.length(); ++i) {
            if (s2t[s[i]] == 0 && t2s[t[i]] == 0) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else if (s2t[s[i]] != t[i] || t2s[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    ASSERT s.isIsomorphic("egg", "add");
    ASSERT !s.isIsomorphic("foo", "bar");
    ASSERT s.isIsomorphic("paper", "title");
    return 0;
}
