/** 046. Permutations

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(const vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, set<int>(nums.begin(), nums.end()), vector<int>());
        return res;
    }
    void dfs(vector<vector<int>>& res, set<int> nums, vector<int> pre) {
        if (nums.size() == 0) {
            res.push_back(pre);
            return;
        }
        for (int i : nums) {
            set<int> s(nums);
            s.erase(s.find(i));
            vector<int> p(pre);
            p.push_back(i);
            dfs(res, s, p);
        }
    }
};

int main() {
    Solution s;
    ASSERT s.permute({1, 2, 3}) == vvi {
        {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}
    };
    return 0;
}
