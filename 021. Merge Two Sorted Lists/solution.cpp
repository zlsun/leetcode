/** 021. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* r;
        if (l1->val < l2->val) {
            r = l1;
            l1 = l1->next;
        } else {
            r = l2;
            l2 = l2->next;
        }
        ListNode* p = r;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return r;
    }
};

int main() {
    Solution s;
    ASSERT s.mergeTwoLists(ListNode::Builder{1, 3, 5}, ListNode::Builder{2, 4, 6})->equal(ListNode::Builder{1, 2, 3, 4, 5, 6});
    ASSERT s.mergeTwoLists(ListNode::Builder{2}, ListNode::Builder{1})->equal(ListNode::Builder{1, 2});
    return 0;
}
