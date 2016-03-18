/** 095. Unique Binary Search Trees II
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

**/

#include <iostream>
#include "../utils.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generate(1, n);
    }
    vector<TreeNode*> generate(int b, int e) {
        vector<TreeNode*> res;
        if (b > e) res.push_back(NULL);
        else if (b == e) res.push_back(new TreeNode(b));
        else {
            for (int k = b; k <= e; ++k) {
                vector<TreeNode*> ls = generate(b, k-1);
                vector<TreeNode*> rs = generate(k+1, e);
                int ll = ls.size(), rl = rs.size();
                for (int i = 0; i < ll; ++i) {
                    for (int j = 0; j < rl; ++j) {
                        TreeNode* node = new TreeNode(k);
                        node->left = ls[i];
                        node->right = rs[j];
                        res.push_back(node);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
