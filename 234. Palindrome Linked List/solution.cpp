/** 234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        auto slow = head, fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        bool res = true;
        auto tail = inverse(slow);
        for (auto p = head, q = tail; q; p = p->next, q = q->next) {
            if (p->val != q->val) {
                res = false;
            }
        }
        inverse(tail);
        return res;
    }
    ListNode* inverse(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            auto next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

int main() {
    Solution s;
    ListNode* l = ListNode::Builder{1, 2, 3, 2, 1};
    ASSERT s.isPalindrome(nullptr);
    ASSERT s.isPalindrome(l);
    ASSERT l->equal(ListNode::Builder{1, 2, 3, 2, 1});
    ASSERT s.inverse(ListNode::Builder{1, 2, 3})->equal(ListNode::Builder{3, 2, 1});
    ASSERT !s.isPalindrome(ListNode::Builder{1, 2});
    ASSERT s.isPalindrome(ListNode::Builder{1, 2, 1});
    ASSERT !s.isPalindrome(ListNode::Builder{1, 2, 2});
    return 0;
}
