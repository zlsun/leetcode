/** 083. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
        auto node = head;
        while (node) {
            auto next = node->next;
            while (next && node->val == next->val) {
                next = next->next;
            }
            node->next = next;
            node = next;
        }
        return head;
    }
};

int main() {
    Solution s;
    ASSERT s.deleteDuplicates(ListNode::Builder{1, 2, 2})->equal(ListNode::Builder{1, 2});
    return 0;
}
