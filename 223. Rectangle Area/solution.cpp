/** 223. Rectangle Area
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.

Credits:Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l = min(max(A, E), C);
        int r = min(max(A, G), C);
        int t = min(max(B, H), D);
        int b = min(max(B, F), D);
        return (C-A)*(D-B) + (G-E)*(H-F) - (r-l)*(t-b);
    }
};

int main() {
    Solution s;
    ASSERT s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) == 45;
    return 0;
}
