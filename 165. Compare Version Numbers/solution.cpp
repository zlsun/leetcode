/** 165. Compare Version Numbers
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37

Credits:Special thanks to @ts for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream is1(version1), is2(version2);
        int i, j;
        while (is1 || is2) {
            i = j = 0;
            is1 >> i; is1.get();
            is2 >> j; is2.get();
            if (i < j) return -1;
            else if (i > j) return 1;
        }
        return 0;
    }
};

int main() {
    Solution s;
    ASSERT s.compareVersion("0.1", "1.1") == -1;
    ASSERT s.compareVersion("1.2", "1.1") == 1;
    ASSERT s.compareVersion("1.2", "1.2") == 0;
    ASSERT s.compareVersion("13.37", "1.2") == 1;
    ASSERT s.compareVersion("1", "1.1") == -1;
    return 0;
}
