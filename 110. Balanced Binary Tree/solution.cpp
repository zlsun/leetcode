/** 110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    bool isBalanced(TreeNode* root) {
        bool balanced;
        judge(root, balanced);
        return balanced;
    }
    int judge(TreeNode* root, bool& balanced) {
        if (!root) {
            balanced = true;
            return 0;
        }
        bool lb = false, rb = false;
        int lh = judge(root->left, lb);
        int rh = judge(root->right, rb);
        balanced = lb && rb && abs(lh - rh) <= 1;
        return max(lh, rh) + 1;
    }
};

int main() {
    Solution s;
    ASSERT s.isBalanced(TreeNode::Builder {});
    ASSERT s.isBalanced(TreeNode::Builder {
        1, {2, 3, 4}, 2
    });
    ASSERT !s.isBalanced(TreeNode::Builder {
        1, {2, 3, {4, 5, 6}}, 2
    });
    return 0;
}
