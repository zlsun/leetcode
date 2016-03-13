/** 242. Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <algorithm>
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
    Solution s;
    ASSERT s.isAnagram("", "") == true;
    ASSERT s.isAnagram("anagram", "nagaram") == true;
    ASSERT s.isAnagram("rat", "car") == false;
    return 0;
}
