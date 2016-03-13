/** 122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int l = prices.size();
        if (l <= 1) return 0;
        int pro = 0;
        for (int i = 1; i < l; ++i) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) pro += diff;
        }
        return pro;
    }
};

int main() {
    Solution s;
    ASSERT s.maxProfit({1}) == 0;
    ASSERT s.maxProfit({1, 2}) == 1;
    ASSERT s.maxProfit({1, 2, 1}) == 1;
    return 0;
}
