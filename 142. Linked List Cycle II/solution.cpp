/** 142. Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode* p = head, *q = head;
        do {
            if (!p->next) return NULL;
            if (!(q->next && q->next->next)) return NULL;
            p = p->next;
            q = q->next->next;
        } while (p != q);
        p = head;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};

int main() {
    Solution s;
    ListNode* list = ListNode::from({1, 2, 3});
    list->next->next->next = list->next;
    ASSERT s.detectCycle(list) == list->next;
    return 0;
}
