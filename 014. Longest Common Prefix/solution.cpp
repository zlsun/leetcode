/** 014. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        int l = strs.size();
        if (l == 0) return "";
        if (l == 1) return strs[0];
        string res = strs[0];
        for (int i = 1; i < l; ++i) {
            const string& s = strs[i];
            int n = min(res.size(), s.size());
            int j;
            for (j = 0; j < n; ++j) {
                if (res[j] != s[j]) {
                    break;
                }
            }
            res = res.substr(0, j);
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.longestCommonPrefix({"123", "12", "1"}) == "1";
    ASSERT s.longestCommonPrefix({"123", "12", "124"}) == "12";
    ASSERT s.longestCommonPrefix({"123", "2"}) == "";
    return 0;
}
