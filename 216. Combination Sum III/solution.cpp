/** 216. Combination Sum III

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Ensure that numbers within the set are sorted in ascending order.

 Example 1:
Input:  k = 3,  n = 7
Output:

[[1,2,4]]

 Example 2:
Input:  k = 3,  n = 9
Output:

[[1,2,6], [1,3,5], [2,3,4]]

Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    vvi combinationSum3(int k, int n) {
        vvi res;
        dfs(res, k, n, {});
        return res;
    }
    void dfs(vvi& res, int k, int n, vi v) {
        if (k == 1) {
            if (n < 10) {
                v.push_back(n);
                res.push_back(v);
            }
            return;
        }
        for (int i = v.empty() ? 1 : v.back() + 1; i < 10 && i < n - i; ++i) {
            v.push_back(i);
            dfs(res, k - 1, n - i, v);
            v.pop_back();
        }
    }
};

int main() {
    Solution s;
    ASSERT s.combinationSum3(3, 7) == vvi {
        {1, 2, 4}
    };
    ASSERT s.combinationSum3(3, 9) == vvi {
        {1, 2, 6}, {1, 3, 5}, {2, 3, 4}
    };
    ASSERT s.combinationSum3(2, 9) == vvi {
        {1, 8}, {2, 7}, {3, 6}, {4, 5}
    };
    zlog s.combinationSum3(2, 18);
    return 0;
}
