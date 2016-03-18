/** 328. Odd Even Linked List
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

Credits:Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* odd_head = NULL, *even_head = NULL, *odd, *even;
        int cnt = 1;
        while (head) {
            if (cnt++ % 2) {
                if (odd_head == NULL) {
                    odd_head = odd = head;
                } else {
                    odd->next = head;
                    odd = head;
                }
            } else {
                if (even_head == NULL) {
                    even_head = even = head;
                } else {
                    even->next = head;
                    even = head;
                }
            }
            head = head->next;
        }
        odd->next = even_head;
        even->next = NULL;
        return odd_head;
    }
};

int main() {
    Solution s;
    ASSERT s.oddEvenList(ListNode::from({1, 2, 3, 4, 5}))->equal(ListNode::from({1, 3, 5, 2, 4}));
    ASSERT s.oddEvenList(ListNode::from({}))->equal(ListNode::from({}));
    ASSERT s.oddEvenList(ListNode::from({1, 3, 5}))->equal(ListNode::from({1, 5, 3}));
    ASSERT s.oddEvenList(ListNode::from({2, 4}))->equal(ListNode::from({2, 4}));
    return 0;
}
