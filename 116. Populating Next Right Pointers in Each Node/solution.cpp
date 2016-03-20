/** 116. Populating Next Right Pointers in Each Node

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

**/

#include <iostream>
#include "../utils.h"
using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <queue>
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        int count = 0;
        queue<TreeLinkNode*> q;
        q.push(root);
        TreeLinkNode* pre = root;
        while (!q.empty()) {
            auto x = q.front(); q.pop();
            ++count;
            if (count & (count - 1)) {
                pre->next = x;
            }
            if (x->left) {
                q.push(x->left);
                q.push(x->right);
            }
            pre = x;
        }
    }
};

int main() {
    Solution s;
    TreeLinkNode* tree = TreeLinkNode::Builder {
        1,
        {2, 4, 5},
        {3, 6, 7}
    };
    s.connect(tree);
    zlog tree->next;
    ASSERT tree->next == NULL;
    ASSERT tree->left->next == tree->right;
    ASSERT tree->left->right->next == tree->right->left;
    return 0;
}
