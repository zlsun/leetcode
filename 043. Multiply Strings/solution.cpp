/** 043. Multiply Strings
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    string multiply(string a, string b) {
        if (a == "0" || b == "0") return "0";
        int la = a.length(), lb = b.length();
        int l = la + lb;
        int* v = new int[l];
        memset(v, 0, sizeof(int) * l);
        for (int i = 0; i < la; ++i) {
            for (int j = 0; j < lb; ++j) {
                v[i + j + 1] += (a[i] - '0') * (b[j] - '0');
            }
        }
        for (int i = l - 1; i > 0; --i) {
            v[i - 1] += v[i] / 10;
            v[i] %= 10;
        }
        for (int i = 0; i < l; ++i) {
            v[i] += '0';
        }
        string r(v[0] == '0' ? v + 1 : v, v + l);
        delete[] v;
        return r;
    }
};

int main() {
    Solution s;
    ASSERT s.multiply("12", "12") == "144";
    ASSERT s.multiply("100", "12") == "1200";
    ASSERT s.multiply("100", "100") == "10000";
    return 0;
}
