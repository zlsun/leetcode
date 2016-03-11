/** 237. Delete Node in a Linked List

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

**/

#include <iostream>
#include "../utils.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* n = node->next;
        node->val = n->val;
        node->next = n->next;
        // delete n;
    }
};

Solution s;

using vl = std::vector<ListNode>;
void test(vl l, int x, vl r) {
    for (size_t i = 0; i < l.size() - 1; ++i) {
        l[i].next = &l[i + 1];
    }
    ListNode* t = &l[0];
    s.deleteNode(&l[x]);
    int idx = 0;
    while (t) {
        ASSERT t->val == r[idx++].val;
        t = t->next;
    }
}

int main() {
    test({1, 2, 3, 4}, 2, {1, 2, 4});
    return 0;
}
