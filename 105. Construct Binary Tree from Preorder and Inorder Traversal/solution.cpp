/** 105. Construct Binary Tree from Preorder and Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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
    typedef vector<int> vi;
    typedef vector<int>::const_iterator vit;
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* build(vit pb, vit pe, vit ib, vit ie) {
        if (pb == pe) return nullptr;
        int v = *pb;
        auto it = find(ib, ie, v);
        auto n = it - ib;
        auto mid = pb + n + 1;
        auto left = build(pb + 1, mid, ib, it);
        auto right = build(mid, pe, it + 1, ie);
        auto tree = new TreeNode(v);
        tree->left = left;
        tree->right = right;
        return tree;
    }
};

int main() {
    Solution s;
    ASSERT s.buildTree({1, 2, 4, 5, 3, 6, 7}, {4, 2, 5, 1, 6, 3, 7})->equal(TreeNode::Builder {
        1, {2, 4, 5}, {3, 6, 7}
    });
    return 0;
}
