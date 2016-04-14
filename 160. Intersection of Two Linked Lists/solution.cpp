/** 160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

Credits:Special thanks to @stellari for adding this problem and creating all test cases.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = length(headA), lb = length(headB);
        int diff = la - lb;
        if (diff > 0) {
            while (diff--) {
                headA = headA->next;
            }
        } else {
            while (diff++) {
                headB = headB->next;
            }
        }
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA == headB ? headA : nullptr;
    }
    int length(ListNode* head) {
        if (!head) return 0;
        return length(head->next) + 1;
    }
};

int main() {
    Solution s;
    ListNode* tail = ListNode::Builder {11, 12, 13};
    ListNode* a = ListNode::Builder {1, {2, tail}};
    ListNode* b = ListNode::Builder {1, {2, {3, tail}}};
    ASSERT s.getIntersectionNode(a, b) == tail;
    return 0;
}
