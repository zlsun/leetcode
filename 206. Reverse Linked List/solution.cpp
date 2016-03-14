/** 206. Reverse Linked List
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

**/

#include <iostream>
#include "../utils.h"
using namespace std;

#include <stack>
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        std::stack<int> s;
        while (head) {
            s.push(head->val);
            head = head->next;
        }
        ListNode* res = new ListNode(s.top()); s.pop();
        ListNode* pre = res;
        while (!s.empty()) {
            pre->next = new ListNode(s.top()); s.pop();
            pre = pre->next;
        }
        return res;
    }
};

int main() {
    Solution s;
    ASSERT s.reverseList(ListNode::from({1, 2}))->equal(ListNode::from({2, 1}));
    return 0;
}
