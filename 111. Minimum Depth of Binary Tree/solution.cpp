/** 111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (!root->left && !root->right) return 1;
        else if (root->left && !root->right) return minDepth(root->left) + 1;
        else if (!root->left && root->right) return minDepth(root->right) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main() {
    Solution s;
    ASSERT s.minDepth(TreeNode::Builder {
        1, nullptr, 2
    }) == 2;
    ASSERT s.minDepth(TreeNode::Builder {
        1, {1, nullptr, 2}, 3
    }) == 2;
    ASSERT s.minDepth(TreeNode::Builder {
        1, 1, {1, 2, 3}
    }) == 2;
    return 0;
}
