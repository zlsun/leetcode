/** 102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return res;
    }
};

int main() {
    Solution s;
    TreeNode* tree = TreeNode::Builder {
        3,
        9,
        {20, 15, 7}
    };
    ASSERT s.levelOrder(tree) == vvi {
        {3},
        {9, 20},
        {15, 7}
    };
    return 0;
}
