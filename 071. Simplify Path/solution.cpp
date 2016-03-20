/** 071. Simplify Path
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.

Corner Cases:

Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path.back() != '/') path += '/';
        vector<string> ps;
        size_t b = 1, e;
        while ((e = path.find('/', b)) != string::npos) {
            if (e > b) ps.push_back(path.substr(b, e - b));
            b = e + 1;
        }
        vector<string> s;
        for (auto& p : ps) {
            if (p == ".") continue;
            else if (p == "..") {
                if (s.size()) s.pop_back();
            } else s.push_back(p);
        }
        string res;
        for (auto& p : s) {
            res += '/' + p;
        }
        return res.empty() ? "/" : res;
    }
};

int main() {
    Solution s;
    ASSERT s.simplifyPath("/home/") == "/home";
    ASSERT s.simplifyPath("/a/./b/../../c/") == "/c";
    ASSERT s.simplifyPath("//") == "/";
    ASSERT s.simplifyPath("///") == "/";
    ASSERT s.simplifyPath("/./") == "/";
    ASSERT s.simplifyPath("/../") == "/";
    ASSERT s.simplifyPath("/...") == "/...";
    ASSERT s.simplifyPath("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///") == "/e/f/g";
    return 0;
}
