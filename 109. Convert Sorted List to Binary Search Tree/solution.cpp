/** 109. Convert Sorted List to Binary Search Tree
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
**/

#include <iostream>
#include "../utils.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        for (ListNode* node = head; node; node = node->next, ++n);
        return build(head, 0, n - 1);
    }
    TreeNode* build(ListNode*& cur, int b, int e) {
        if (b > e) return NULL;
        int m = (b + e) / 2;
        auto node = new TreeNode(-1);
        node->left = build(cur, b, m - 1);
        node->val = cur->val;
        cur = cur->next;
        node->right = build(cur, m + 1, e);
        return node;
    }
};

int main() {
    Solution s;
    ASSERT s.sortedListToBST(ListNode::from({1, 2, 3}))->equal(TreeNode::Builder{2, 1, 3});
    return 0;
}
