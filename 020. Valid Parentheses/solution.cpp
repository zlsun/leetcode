/** 020. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        map<char, char> par {{')', '('}, {']', '['}, {'}', '{'}};
        for (auto c : s) {
            switch (c) {
                case '(': case '[': case '{':
                    S.push(c);
                    break;
                case ')': case ']': case '}':
                    if (S.empty() || S.top() != par[c]) return false;
                    S.pop();
            }
        }
        return S.empty();
    }
};

int main() {
    Solution s;
    ASSERT s.isValid("([])");
    ASSERT s.isValid("([]()){}");
    ASSERT !s.isValid("([](){}");
    ASSERT !s.isValid("[])");
    return 0;
}
