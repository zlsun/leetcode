/** 107. Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        res.emplace_back();
        while (!q.empty()) {
            auto x = q.front(); q.pop();
            if (x == nullptr) {
                if (!q.empty()) {
                    res.emplace_back();
                    q.push(nullptr);
                }
                continue;
            }
            res.back().push_back(x->val);
            if (x->left) q.push(x->left);
            if (x->right) q.push(x->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
