/** 278. First Bad Version

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

// Forward declaration of isBadVersion API.
int firstBad;
bool isBadVersion(int version) {
    return version >= firstBad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while (i + 1 < j) {
            int m = i + (j - i) / 2;
            if (isBadVersion(m)) j = m;
            else i = m;
        }
        return isBadVersion(i) ? i : j;
    }
};

int main() {
    Solution s;
    int n = 20;
    for (int i = 1; i <= n; ++i) {
        firstBad = i;
        ASSERT s.firstBadVersion(n) == firstBad;
    }
    return 0;
}
