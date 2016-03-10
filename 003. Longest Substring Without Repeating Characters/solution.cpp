/** 003. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool has[256] = {0};
        int b = 0, e = 1, l = s.length(), m = 0;
        if (l <= 1) return l;
        has[s[b]] = 1;
        while (e < l) {
            while (has[s[e]]) {
                has[s[b]] = 0;
                ++b;
            }
            has[s[e]] = 1;
            ++e;
            m = std::max(m, e - b);
        }
        return m;
    }
};

int main() {
    Solution s;
    ASSERT s.lengthOfLongestSubstring("abcabcbb") == 3;
    ASSERT s.lengthOfLongestSubstring("bbbbb") == 1;
    ASSERT s.lengthOfLongestSubstring("b") == 1;
    ASSERT s.lengthOfLongestSubstring("") == 0;
    ASSERT s.lengthOfLongestSubstring("dvdf") == 3;
    return 0;
}
