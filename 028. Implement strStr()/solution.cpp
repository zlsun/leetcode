/** 028. Implement strStr()

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> getNext(string& s) {
        int l = s.length();
        vector<int> next(l);
        next[0] = 0;
        for (int i = 1, q = 0; i < l; ++i) {
            while (q && s[i] != s[q])
                q = next[q - 1];
            if (s[i] == s[q])
                ++q;
            next[i] = q;
        }
        return next;
    }
    int kmp(string& s1, string& s2) {
        int l1 = s1.length(), l2 = s2.length();
        vector<int> next = getNext(s2);
        for (int i = 0, q = 0; i < l1; ++i) {
            while (q && s1[i] != s2[q])
                q = next[q - 1];
            if (s1[i] == s2[q])
                ++q;
            if (q == l2)
                return i - q + 1;
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty() || haystack.length() < needle.length()) return -1;
        return kmp(haystack, needle);
    }
};

int main() {
    Solution s;
    ASSERT s.strStr("a", "") == 0;
    ASSERT s.strStr("a", "a") == 0;
    ASSERT s.strStr("ba", "a") == 1;
    return 0;
}
