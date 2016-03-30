/** 054. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        vector<int> res;
        if (m == 0 || n == 0) return res;
        int i = 0, j = 0;
        int di = 0, dj = 1;
        int x = 1;
        while (x <= m * n) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
            if (i + di < 0 || i + di >= m || j + dj < 0 || j + dj >= n || matrix[i + di][j + dj] == INT_MAX) {
                swap(di, dj);
                dj = -dj;
            }
            i += di;
            j += dj;
            ++x;
        }
        return res;
    }
};

int main() {
    Solution s;
    vvi v;
    ASSERT s.spiralOrder(v) == vi {};
    v = vvi {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    ASSERT s.spiralOrder(v) == vi {1, 2, 3, 6, 9, 8, 7, 4, 5};
    v = vvi {
        { 2, 5, 8 },
        { 4, 0,-1 }
    };
    ASSERT s.spiralOrder(v) == vi {2, 5, 8, -1, 0, 4};
    v = vvi {{7}, {9}, {6}};
    ASSERT s.spiralOrder(v) == vi {7, 9, 6};
    v = vvi {{7}};
    ASSERT s.spiralOrder(v) == vi {7};
    return 0;
}
