/** 077. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        dfs(res, n, k, 1, v);
        return res;
    }
    void dfs(vector<vector<int>>& res, int n, int k, int from, vector<int>& v) {
        if (k == 0) {
            res.push_back(v);
            return;
        }
        for (int i = from; i <= n; ++i) {
            v.push_back(i);
            dfs(res, n, k - 1, i + 1, v);
            v.pop_back();
        }
    }
};

int main() {
    Solution s;
    ASSERT s.combine(4, 2) == vvi {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 4},
        {3, 4},
    };
    return 0;
}
