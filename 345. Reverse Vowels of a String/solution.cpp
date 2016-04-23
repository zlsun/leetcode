/** 345. Reverse Vowels of a String
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        auto b = s.begin();
        auto rb = s.rbegin();
        string res;
        for (; b != s.end(); ++b) {
            if (isVowel(*b)) {
                while (!isVowel(*rb)) ++rb;
                res += *rb++;
            } else {
                res += *b;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.reverseVowels("aA") == "Aa";
    ASSERT s.reverseVowels("hello") == "holle";
    ASSERT s.reverseVowels("leetcode") == "leotcede";
    return 0;
}
