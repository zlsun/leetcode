/** 002. Add Two Numbers

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(-1);
        ListNode* res = root;
        int inc = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + inc;
            inc = sum / 10;
            sum %= 10;
            res->next = new ListNode(sum);
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* l = l1 ? l1 : (l2 ? l2 : NULL);
        while (l) {
            int sum = l->val + inc;
            inc = sum / 10;
            sum %= 10;
            res->next = new ListNode(sum);
            res = res->next;
            l = l->next;
        }
        if (inc) {
            res->next = new ListNode(inc);
        }
        res = root->next;
        delete root;
        return res;
    }
};

Solution s;

using vl = std::vector<ListNode>;
void test(vl l1, vl l2, vl res) {
    vl* ls[] {&l1, &l2};
    for (auto& pl : ls) {
        vl& l = *pl;
        for (size_t i = 0; i < l.size() - 1; ++i) {
            l[i].next = &l[i + 1];
        }
    }
    ListNode* r = s.addTwoNumbers(&l1[0], &l2[0]);
    int idx = 0;
    while (r) {
        ASSERT r->val == res[idx++].val;
        r = r->next;
    }
}

int main() {
    test({2, 4, 3}, {5, 6, 4}, {7, 0, 8});
    test({2, 4}, {5, 6, 4}, {7, 0, 5});
    test({2, 4}, {5, 6}, {7, 0, 1});
    return 0;
}
