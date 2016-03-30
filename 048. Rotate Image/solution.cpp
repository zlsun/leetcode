/** 048. Rotate Image
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int ii = n - i - 1;
                int jj = n - j - 1;
                int tmp = matrix[jj][i];
                matrix[jj][i] = matrix[ii][jj];
                matrix[ii][jj] = matrix[j][ii];
                matrix[j][ii] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
};

int main() {
    Solution s;
    vvi m {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    s.rotate(m);
    ASSERT m == vvi {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    m = vvi {
        {1, 2},
        {3, 4}
    };
    s.rotate(m);
    ASSERT m == vvi {
        {3, 1},
        {4, 2}
    };
    return 0;
}
