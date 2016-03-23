/** 331. Verify Preorder Serialization of a Binary Tree
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true
Example 2:
"1,#"
Return false
Example 3:
"9,#,#,1"
Return false

Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    vector<string> split(string s, char sp = ' ') {
        stringstream ss(s);
        vector<string> res;
        while (getline(ss, s, sp)) {
            res.push_back(s);
        }
        return res;
    }
    bool isValidSerialization(string preorder) {
        int diff = 1;
        for (auto& i : split(preorder, ',')) {
            if (--diff < 0) return false;
            if (i != "#") diff += 2;
        }
        return diff == 0;
    }
};

int main() {
    Solution s;
    ASSERT s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") == true;
    ASSERT s.isValidSerialization("1,#") == false;
    ASSERT s.isValidSerialization("9,#,#,1") == false;
    return 0;
}
