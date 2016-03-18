/** 078. Subsets

Given a set of distinct integers, nums, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <algorithm>
#include <iterator>
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        sort(nums.begin(), nums.end());
        for (auto n : nums) {
            vector<vector<int>> v;
            for (auto r : res) {
                r.push_back(n);
                v.push_back(r);
            }
            copy(v.begin(), v.end(), std::back_inserter(res));
        }
        return res;
    }
};

int main() {
    Solution s;
    vi v{1, 2, 3};
    ASSERT s.subsets(v) == vvi {
        {},
        {1},
        {2},
        {1, 2},
        {3},
        {1, 3},
        {2, 3},
        {1, 2, 3}
    };
    return 0;
}
