/** 086. Partition List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
    ListNode* partition(ListNode* head, int x) {
        ListNode ls(-1), geq(-1);
        ListNode* last_ls = &ls, *last_geq = &geq;
        while (head) {
            if (head->val < x) {
                last_ls->next = head;
                last_ls = last_ls->next;
            } else {
                last_geq->next = head;
                last_geq = last_geq->next;
            }
            head = head->next;
        }
        last_geq->next = nullptr;
        last_ls->next = geq.next;
        return ls.next;
    }
};

int main() {
    Solution s;
    using L = ListNode::Builder;
    ASSERT s.partition(L{1, 4, 3, 2, 5, 2}, 3)->equal(L{1, 2, 2, 4, 3, 5});
    return 0;
}
