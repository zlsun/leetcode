/** 347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (auto i : nums) counter[i]++;
        vector<pair<int, int>> v(counter.begin(), counter.end());
        nth_element(v.begin(), v.begin() + k, v.end(), [](auto a, auto b) { return a.second > b.second; });
        vector<int> res;
        transform(v.begin(), v.begin() + k, back_inserter(res), [](auto p) { return p.first; });
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.topKFrequent(vi{1, 1, 1, 2, 2, 3}, 2) == vi{1, 2};
    return 0;
}
