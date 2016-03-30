/** 073. Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        if (m == 0 || n == 0) return;
        bool row, col;
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                row = 1;
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col = 1;
                break;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (col) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    Solution s;
    vvi m {
        {1, 0, 1},
        {0, 1, 1},
        {1, 1, 1},
    };
    s.setZeroes(m);
    ASSERT m == vvi {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 1},
    };
    m = vvi {{1, 0}};
    s.setZeroes(m);
    ASSERT m == vvi {{0, 0}};
    return 0;
}
