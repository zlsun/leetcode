/** 058. Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        s.clear();
        while (iss >> s);
        return s.length();
    }
};

int main() {
    Solution s;
    ASSERT s.lengthOfLastWord("") == 0;
    ASSERT s.lengthOfLastWord(" ") == 0;
    ASSERT s.lengthOfLastWord("world") == 5;
    ASSERT s.lengthOfLastWord("Hello world") == 5;
    return 0;
}
