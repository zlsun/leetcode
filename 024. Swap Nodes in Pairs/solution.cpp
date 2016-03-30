/** 024. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto pre = head;
        head = head->next;
        pre->next = head->next;
        head->next = pre;
        while (pre->next && pre->next->next) {
            auto p = pre->next;
            auto q = p->next;
            pre->next = q;
            p->next = q->next;
            q->next = p;
            pre = p;
        }
        return head;
    }
};

int main() {
    Solution s;
    ASSERT s.swapPairs(ListNode::Builder{})->equal(ListNode::Builder{});
    ASSERT s.swapPairs(ListNode::Builder{1})->equal(ListNode::Builder{1});
    ASSERT s.swapPairs(ListNode::Builder{1, 2})->equal(ListNode::Builder{2, 1});
    ASSERT s.swapPairs(ListNode::Builder{1, 2, 3, 4})->equal(ListNode::Builder{2, 1, 4, 3});
    ASSERT s.swapPairs(ListNode::Builder{1, 2, 3, 4, 5})->equal(ListNode::Builder{2, 1, 4, 3, 5});
    return 0;
}
