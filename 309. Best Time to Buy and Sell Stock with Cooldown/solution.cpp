/** 309. Best Time to Buy and Sell Stock with Cooldown
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]

Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int curNo, preNo, curHas;
        curNo = preNo = 0;
        curHas = -prices[0];
        for (int i = 1; i < n; ++i) {
            int tmp = curNo;
            curNo = max(curNo, curHas + prices[i]);
            curHas = max(curHas, preNo - prices[i]);
            preNo = tmp;
        }
        return curNo;
    }
};

int main() {
    Solution s;
    ASSERT s.maxProfit({1, 2, 3, 0, 2}) == 3;
    return 0;
}
