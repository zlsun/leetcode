/** 141. Linked List Cycle

Given a linked list, determine if it has a cycle in it.

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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* p = head, *q = head;
        do {
            if (!(q->next && q->next->next)) return false;
            p = p->next;
            q = q->next->next;
        } while (p != q);
        return true;
    }
};

int main() {
    Solution s;
    ASSERT !s.hasCycle(ListNode::from({}));
    ASSERT !s.hasCycle(ListNode::from({1, 2, 3}));
    ListNode* list = ListNode::from({1, 2});
    list->next->next = list;
    ASSERT s.hasCycle(list);
    return 0;
}
