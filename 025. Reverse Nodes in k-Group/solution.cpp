/** 025. Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == nullptr) return head;
        ListNode* node = head;
        int idx;
        for (idx = 0; idx < k && node; ++idx) {
            node = node->next;
        }
        if (idx != k) return head;
        node = reverseKGroup(node, k);
        ListNode* pre = head;
        ListNode* cur = head->next;
        head->next = node;
        while (--idx) {
            ListNode* p = cur->next;
            cur->next = pre;
            pre = cur;
            cur = p;
        }
        return pre;
    }
};

int main() {
    Solution s;
    ASSERT s.reverseKGroup(ListNode::Builder{1, 2}, 3)->equal(ListNode::Builder{1, 2});
    ASSERT s.reverseKGroup(ListNode::Builder{1, 2, 3, 4, 5}, 2)->equal(ListNode::Builder{2, 1, 4, 3, 5});
    ASSERT s.reverseKGroup(ListNode::Builder{1, 2, 3, 4, 5}, 3)->equal(ListNode::Builder{3, 2, 1, 4, 5});
    return 0;
}
