/** 121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int mi = prices[0];
        int res = 0;
        for (auto p : prices) {
            mi = min(mi, p);
            res = max(res, p - mi);
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.maxProfit({1, 1}) == 0;
    ASSERT s.maxProfit({1, 2}) == 1;
    ASSERT s.maxProfit({2, 1}) == 0;
    return 0;
}
