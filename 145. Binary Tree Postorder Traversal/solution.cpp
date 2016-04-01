/** 145. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* last = nullptr;
        while (!s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode* top = s.top();
                if (top->right == nullptr || top->right == last) {
                    res.push_back(top->val);
                    last = top;
                    s.pop();
                } else {
                    root = top->right;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.postorderTraversal(TreeNode::Builder {
        1, nullptr, {2, 3}
    }) == vi {3, 2, 1};
    return 0;
}
