/** 104. Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode* l = NULL, TreeNode* r = NULL) : val(x), left(l), right(r) {}
    struct Builder {
        TreeNode* p;
        Builder(TreeNode* p = nullptr): p(p) {}
        Builder(int d, Builder l = Builder(), Builder r = Builder())
            : p(new TreeNode(d, l.p, r.p)) {}
        operator TreeNode* () const {
            return p;
        }
    };
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    Solution s;
    TreeNode* tree = TreeNode::Builder {
        1,
        { 2, {4}, {5} },
        { 3 }
    };
    ASSERT s.maxDepth(tree) == 3;
    return 0;
}
