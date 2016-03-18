/** 230. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

  Try to utilize the property of a BST.
  What if you could modify the BST node's structure?
  The optimal runtime complexity is O(height of BST).

Credits:Special thanks to @ts for adding this problem and creating all test cases.
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
#include <stack>
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* node;
        for (node = root; node; node = node->left)
            s.push(node);
        int cnt = 0;
        while (!s.empty() && cnt < k) {
            node = s.top(); s.pop();
            ++cnt;
            for (auto n = node->right; n; n = n->left)
                s.push(n);
        }
        return node->val;
    }
};

int main() {
    Solution s;
    ASSERT s.kthSmallest(TreeNode::Builder{
        1, 2, 3
    }, 3) == 3;
    return 0;
}
