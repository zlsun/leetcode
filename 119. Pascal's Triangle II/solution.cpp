/** 119. Pascal's Triangle II
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r1(rowIndex + 1), r2(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            r2[0] = r2[i] = 1;
            for (int j = 1; j < i; ++j) {
                r2[j] = r1[j - 1] + r1[j];
            }
            swap(r1, r2);
        }
        return r1;
    }
};

int main() {
    Solution s;
    ASSERT s.getRow(0) == vi {1};
    ASSERT s.getRow(1) == vi {1, 1};
    ASSERT s.getRow(2) == vi {1, 2, 1};
    ASSERT s.getRow(3) == vi {1, 3, 3, 1};
    ASSERT s.getRow(4) == vi {1, 4, 6, 4, 1};
    // ASSERT s.getRow(5) == vi {1, 5, 10, 10, 5, 1};
    return 0;
}
