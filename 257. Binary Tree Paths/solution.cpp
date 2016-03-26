/** 257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:
["1->2->5", "1->3"]

Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        dfs(res, root, to_string(root->val));
        return res;
    }
    void dfs(vector<string>& res, TreeNode* root, string path) {
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }
        if (root->left) {
            dfs(res, root->left, path + "->" + to_string(root->left->val));
        }
        if (root->right) {
            dfs(res, root->right, path + "->" + to_string(root->right->val));
        }
    }
};

int main() {
    Solution s;
    ASSERT s.binaryTreePaths(TreeNode::Builder {
        1, {2, nullptr, 5}, 3
    }) == vector<string>{"1->2->5", "1->3"};
    return 0;
}
