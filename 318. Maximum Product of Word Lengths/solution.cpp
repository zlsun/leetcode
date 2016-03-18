/** 318. Maximum Product of Word Lengths

    Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
    You may assume that each word will contain only lower case letters.
    If no such two words exist, return 0.

    Example 1:

    Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
    Return 16
    The two words can be "abcw", "xtfn".

    Example 2:

    Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
    Return 4
    The two words can be "ab", "cd".

    Example 3:

    Given ["a", "aa", "aaa", "aaaa"]
    Return 0
    No such pair of words.

Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <algorithm>
class Solution {
public:
    int maxProduct(const vector<string>& words) {
        int n = words.size();
        vector<int> hash(n);
        for (int i = 0; i < n; ++i) {
            int l = words[i].length();
            for (int j = 0; j < l; ++j) {
                hash[i] |= 1 << (words[i][j] - 'a');
            }
        }
        size_t m = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((hash[i] & hash[j]) == 0) {
                    m = max(m, words[i].length() * words[j].length());
                }
            }
        }
        return m;
    }
};

int main() {
    Solution s;
    ASSERT s.maxProduct({}) == 0;
    ASSERT s.maxProduct({"abcw", "baz", "foo", "bar", "xtfn", "abcdef"}) == 16;
    ASSERT s.maxProduct({"a", "ab", "abc", "d", "cd", "bcd", "abcd"}) == 4;
    ASSERT s.maxProduct({"a", "aa", "aaa", "aaaa"}) == 0;
    return 0;
}
