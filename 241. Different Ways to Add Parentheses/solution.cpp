/** 241. Different Ways to Add Parentheses
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1
Input: "2-1-1".
((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]

Example 2
Input: "2*3-4*5"
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int l = input.length();
        for (int i = 0; i < l; ++i) {
            char c = input[i];
            if (c != '+' && c != '-' && c != '*') continue;
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1, l - (i + 1)));
            int r;
            for (int a : left) {
                for (int b : right) {
                    switch (c) {
                        case '+': r = a + b; break;
                        case '-': r = a - b; break;
                        case '*': r = a * b; break;
                    }
                    res.push_back(r);
                }
            }
        }
        if (res.empty()) {
            res.push_back(stoi(input));
        } else {
            sort(res.begin(), res.end());
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.diffWaysToCompute("2-1-1") == vi{0, 2};
    ASSERT s.diffWaysToCompute("2*3-4*5") == vi{-34, -14, -10, -10, 10};
    return 0;
}
