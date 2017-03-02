/** 203. Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        if (head == NULL) return NULL;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur) {
            ListNode* next = cur->next;
            if (cur->val == val) {
                pre->next = next;
                // delete cur;
            } else {
                pre = cur;
            }
            cur = next;
        }
        return head;
    }
};

Solution s;

using vl = std::vector<ListNode>;
void test(vl l, int x, vl r) {
    for (size_t i = 0; i < l.size() - 1; ++i) {
        l[i].next = &l[i + 1];
    }
    ListNode* t = s.removeElements(&l[0], x);
    int idx = 0;
    while (t) {
        ASSERT t->val == r[idx++].val;
        t = t->next;
    }
}

int main() {
    test({1, 2, 6, 3, 4, 5, 6}, 6, {1, 2, 3, 4, 5});
    test({1, 2, 1}, 1, {2});
    test({1}, 1, {});
    return 0;
}
