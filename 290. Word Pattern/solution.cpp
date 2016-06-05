/** 290. Word Pattern
Given a pattern and a string str, find if str follows the same pattern.
 Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:

pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

Credits:Special thanks to @minglotus6 for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        istringstream iss(str);
        string s;
        for (char c : pattern) {
            if (!(iss >> s)) return false;
            if (p2s.find(c) == p2s.end() && s2p.find(s) == s2p.end()) {
                p2s[c] = s;
                s2p[s] = c;
            } else if (p2s[c] != s && s2p[s] != c) {
                return false;
            }
        }
        return !(iss >> s);
    }
};

int main() {
    Solution s;
    ASSERT s.wordPattern("abba", "dog cat cat dog");
    ASSERT !s.wordPattern("abba", "dog cat cat fish");
    ASSERT !s.wordPattern("aaaa", "dog cat cat dog");
    ASSERT !s.wordPattern("abba", "dog dog dog dog");
    ASSERT !s.wordPattern("aaa", "aa aa aa aa");
    return 0;
}
