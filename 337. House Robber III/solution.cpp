/** 337. House Robber III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

     3
    / \
   2   3
    \   \
     3   1

Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:

     3
    / \
   4   5
  / \   \
 1   3   1

Maximum amount of money the thief can rob = 4 + 5 = 9.

Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
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
    int rob(TreeNode* root) {
        return dfs(root).first;
    }
    typedef pair<int, int> pii;
    pii dfs(TreeNode* root) {
        pii p = make_pair(0, 0);
        if (root) {
            pii l = dfs(root->left);
            pii r = dfs(root->right);
            p.second = l.first + r.first;
            p.first = max(p.second, l.second + r.second + root->val);
        }
        return p;
    }
};

int main() {
    Solution s;
    TreeNode* tree = TreeNode::Builder {
        3,
        {2, nullptr, 3},
        {3, nullptr, 1}
    };
    ASSERT s.rob(tree) == 7;
    tree = TreeNode::Builder {
        3,
        {4, 1, 3},
        {5, nullptr, 1}
    };
    ASSERT s.rob(tree) == 9;
    tree = TreeNode::Builder {
        4,
        {1, 2, 3},
        nullptr
    };
    ASSERT s.rob(tree) == 9;
    return 0;
}
