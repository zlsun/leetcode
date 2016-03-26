/** 199. Binary Tree Right Side View
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4].

Credits:Special thanks to @amrsaqr for adding this problem and creating all test cases.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (root == NULL) return v;
        queue<TreeNode*> q;
        TreeNode* cur;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                cur = q.front(); q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            v.push_back(cur->val);
        }
        return v;
    }
};

int main() {
    Solution s;
    TreeNode* tree = TreeNode::Builder {
        40, {20, 10, 30}, {60, {50, 41, nullptr}, 70}
    };
    ASSERT s.rightSideView(tree) == vi{40, 60, 70, 41};
    return 0;
}
