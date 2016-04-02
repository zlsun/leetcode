/** 118. Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> m(n);
        for (int i = 0; i < n; ++i) {
            m[i].resize(i + 1);
            m[i][0] = m[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
            }
        }
        return m;
    }
};

int main() {
    Solution s;
    ASSERT s.generate(1) == vvi {{1}};
    ASSERT s.generate(5) == vvi {
        {1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1}
    };
    return 0;
}
