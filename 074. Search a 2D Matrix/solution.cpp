/** 074. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        if (m == 0 || n == 0) return false;
        vector<int> col;
        for (auto& v : matrix) col.push_back(v[0]);
        int l = lower_bound(col.begin(), col.end(), target) - col.begin();
        l = max(0, l - 1);
        int u = upper_bound(col.begin(), col.end(), target) - col.begin();
        for (int i = l; i < u; ++i) {
            auto& row = matrix[i];
            if (binary_search(row.begin(), row.end(), target)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vvi m {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    ASSERT s.searchMatrix(m, 1);
    ASSERT s.searchMatrix(m, 3);
    ASSERT s.searchMatrix(m, 7);
    ASSERT s.searchMatrix(m, 10);
    ASSERT !s.searchMatrix(m, 12);
    return 0;
}
