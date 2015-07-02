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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int length = 0;
        ListNode* old_tail = head;
        while (old_tail && old_tail->next) {
            ++length;
            old_tail = old_tail->next;
        }
        ++length;
        k = k % length;
        if (k == 0)
            return head;
        ListNode* new_tail = head;
        for (int i = 0; i < length-k-1; ++i)
            new_tail = new_tail->next;
        ListNode* new_head = new_tail->next;
        new_tail->next = NULL;
        old_tail->next = head;
        return new_head;
    }
};
