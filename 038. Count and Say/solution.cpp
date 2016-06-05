/** 038. Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        while (--n) {
            char pre = res[0];
            int count = 0;
            string next;
            for (char c : res) {
                if (c == pre) {
                    ++count;
                } else {
                    next += to_string(count) + pre;
                    count = 1;
                }
                pre = c;
            }
            next += to_string(count) + pre;
            res = next;
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.countAndSay(1) == "1";
    ASSERT s.countAndSay(2) == "11";
    ASSERT s.countAndSay(3) == "21";
    ASSERT s.countAndSay(4) == "1211";
    ASSERT s.countAndSay(5) == "111221";
    ASSERT s.countAndSay(6) == "312211";
    ASSERT s.countAndSay(7) == "13112221";
    return 0;
}
