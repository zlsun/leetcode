/** 061. Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        for (ListNode* p = head; p; p = p->next, ++n);
        if (n == 0 || k % n == 0) return head;
        k %= n;
        ListNode* kth = getNth(head, n - k);
        ListNode* pre = getNth(head, n - k - 1);
        ListNode* end = getNth(head, n - 1);
        pre->next = nullptr;
        end->next = head;
        return kth;
    }
    ListNode* getNth(ListNode* p, int n) {
        for (; n; p = p->next, --n);
        return p;
    }
};

int main() {
    Solution s;
    ASSERT s.rotateRight(ListNode::Builder{1, 2, 3, 4, 5}, 2)->equal(ListNode::Builder{4, 5, 1, 2, 3});
    return 0;
}
