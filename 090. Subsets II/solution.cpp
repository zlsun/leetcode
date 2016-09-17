/** 090. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

**/

#include <iostream>
#include "../utils.h"
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class Solution {
public:
    vvi subsetsWithDup(vi& nums) {
        sort(nums.begin(), nums.end());
        vpii count;
        int idx = -1;
        int pre = INT_MAX;
        for (auto i : nums) {
            if (i != pre) {
                idx++;
                count.push_back(pii(i, 0));
            }
            count[idx].second++;
            pre = i;
        }
        vvi res;
        vi cur;
        dfs(res, cur, count, 0);
        return res;
    }
    void dfs(vvi& res, vi& cur, vpii& count, int idx) {
        string ident(idx * 4, ' ');
        if (idx == count.size()) {
            res.push_back(cur);
            return;
        }
        pii& p = count[idx];
        int num = p.first, cnt = p.second;
        for (int rep = 0; rep <= cnt; ++rep) {
            for (int i = 0; i < rep; ++i) {
                cur.push_back(num);
            }
            dfs(res, cur, count, idx + 1);
            for (int i = 0; i < rep; ++i) {
                cur.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    vi v {1, 2, 2};
    ASSERT s.subsetsWithDup(v) == vvi{{}, {2}, {2, 2}, {1}, {1, 2}, {1, 2, 2}};
    v = {-1, 1, 2};
    ASSERT s.subsetsWithDup(v) == vvi{{}, {2}, {1}, {1, 2}, {-1}, {-1, 2}, {-1, 1}, {-1, 1, 2}};
    return 0;
}
