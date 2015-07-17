// by hxdone

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
    void deleteNode(ListNode* node) {
        ListNode* new_tail = node;
        while (node->next) {
            node->val = node->next->val;
            new_tail = node;
            node = node->next;
        }
        new_tail->next = NULL;
    }
};
