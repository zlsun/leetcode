/** 022. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    void dfs(vector<string>& res, string par, int l, int r) {
        if (l < 0 || l > r) return;
        if (r == 0) {
            res.push_back(par);
            return;
        }
        dfs(res, par + "(", l - 1, r);
        dfs(res, par + ")", l, r - 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.generateParenthesis(3) == vector<string> {
        "((()))", "(()())", "(())()", "()(())", "()()()"
    };
    return 0;
}
