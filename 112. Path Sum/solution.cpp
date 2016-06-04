/** 112. Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) return root->val == sum;
        int rest = sum - root->val;
        return hasPathSum(root->left, rest) || hasPathSum(root->right, rest);
    }
};

int main() {
    Solution s;
    ASSERT !s.hasPathSum(TreeNode::Builder{}, 0);
    ASSERT s.hasPathSum(TreeNode::Builder{1}, 1);
    ASSERT !s.hasPathSum(TreeNode::Builder{1, 2}, 1);
    ASSERT s.hasPathSum(TreeNode::Builder{1, 2}, 3);
    ASSERT s.hasPathSum(TreeNode::Builder{
        5,
        {4, {11, 7, 2}},
        {8, 13, {4, nullptr, 1}}
    }, 22);
    return 0;
}
