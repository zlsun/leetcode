/** 117. Populating Next Right Pointers in Each Node II
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?

Note:
You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

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
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode dummy(-1);
            for (auto cur = root, pre = &dummy; cur; cur = cur->next) {
                if (cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
            }
            root = dummy.next;
        }
    }
};

int main() {
    Solution s;
    TreeLinkNode* tree = TreeLinkNode::Builder {
        1,
        {2, 4, 5},
        {3, nullptr, 7}
    };
    s.connect(tree);
    ASSERT tree->next == NULL;
    ASSERT tree->left->next == tree->right;
    ASSERT tree->left->right->next == tree->right->right;
    tree = TreeLinkNode::Builder {
        3,
        9,
        {20, 15, 7}
    };
    s.connect(tree);
    ASSERT tree->next == NULL;
    ASSERT tree->left->next == tree->right;
    ASSERT tree->right->left->next == tree->right->right;
    return 0;
}
