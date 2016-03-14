/** 052. N-Queens II
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
private:
    int fullrow;
    int ans;
public:
    int totalNQueens(int n) {
        ans = 0;
        fullrow = (1 << n) - 1;
        search(0, 0, 0, 0);
        return ans;
    }
    void search(int idx, int row, int ld, int rd) {
        int pos, p;
        if (row == fullrow) {
            ++ans;
        } else {
            pos = fullrow & (~(row | ld | rd));
            while (pos) {
                p = pos & -pos;
                pos -= p;
                search(idx + 1, row | p, (ld | p) << 1, (rd | p) >> 1);
            }
        }
    }
};


int main() {
    Solution s;
    ASSERT s.totalNQueens(4) == 2;
    return 0;
}
