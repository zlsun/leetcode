/** 144. Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
**/

#include <iostream>
#include "../utils.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <stack>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> s;
        vector<int> v;
        s.push(root);
        while(!s.empty()) {
            TreeNode* x = s.top();
            s.pop();
            if (!x) continue;
            v.push_back(x->val);
            s.push(x->right);
            s.push(x->left);
        }
        return v;
    }
};

int main() {
    Solution s;
    return 0;
}
