/** 108. Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    TreeNode* build(const vector<int>& v, int b, int e) {
        if (b > e) return NULL;
        int m = (b + e) / 2;
        auto node = new TreeNode(v[m]);
        node->left = build(v, b, m - 1);
        node->right = build(v, m + 1, e);
        return node;
    }
};

int main() {
    Solution s;
    ASSERT s.sortedArrayToBST({1, 2, 3})->equal(TreeNode::Builder{2, 1, 3});
    return 0;
}
