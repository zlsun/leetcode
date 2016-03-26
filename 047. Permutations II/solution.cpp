/** 047. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(const vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, vector<int>());
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int> nums, vector<int> pre) {
        if (nums.size() == 0) {
            res.push_back(pre);
            return;
        }
        set<int> ns(nums.begin(), nums.end());
        for (int i : ns) {
            vector<int> s(nums);
            s.erase(find(s.begin(), s.end(), i));
            vector<int> p(pre);
            p.push_back(i);
            dfs(res, s, p);
        }
    }
};

int main() {
    Solution s;
    ASSERT s.permuteUnique({1, 1, 2}) == vvi {
        {1, 1, 2}, {1, 2, 1}, {2, 1, 1}
    };
    return 0;
}
