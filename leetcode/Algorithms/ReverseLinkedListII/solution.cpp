// one-pass solution by hxdone

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* node_prev_m = NULL, *reverse_head = NULL, *reverse_tail = NULL;
        ListNode* cur = head;
        for (int i = 1; i <= n; ++i) {
            if (i < m-1) {
                cur = cur->next;
            } else if (i == m-1) {
                node_prev_m = cur;
                cur = cur->next;
                //node_prev_m->next = NULL;
            } else if (i == m) {
                reverse_head = cur;
                reverse_tail = cur;
                cur = cur->next;
            } else  if (i > m && i < n) {
                ListNode* tmp = cur;
                cur = cur->next;
                tmp->next = reverse_head;
                reverse_head = tmp;
            } else {
                reverse_tail->next = cur->next;
                cur->next = reverse_head;
                reverse_head = cur;
            }
        }
        if (!node_prev_m)
            return reverse_head;
        else {
            node_prev_m ->next = reverse_head;
            return head;
        }
    }
};
