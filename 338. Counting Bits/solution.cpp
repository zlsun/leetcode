/** 338. Counting Bits
Given a non negative integer number num. For every numbers i in the range 0 &le; i &le; num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount  in c++ or in any other language.

  You should make use of what you have produced already.
  Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
  Or does the odd/even status of the number help you in calculating the number of 1s?

Credits:Special thanks to @ syedee  for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1);
        v[0] = 0;
        for (int i = 1; i <= num; ++i) {
            if (i & 1) v[i] = v[i / 2] + 1;
            else v[i] = v[i / 2];
        }
        return v;
    }
};

int main() {
    Solution s;
    ASSERT s.countBits(5) == vector<int> {0, 1, 1, 2, 1, 2};
    return 0;
}
