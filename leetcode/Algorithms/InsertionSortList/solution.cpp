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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || head->next == NULL)
            return head;
        ListNode* unorder_head = head->next;
        head->next = NULL;
        while (unorder_head != NULL) {
            if (head->val > unorder_head->val) {
                ListNode* tmp = unorder_head;
                unorder_head = unorder_head->next;
                tmp->next = head;
                head = tmp;
                continue;
            }
            ListNode* p = head;
            for (; p->next != NULL && p->next->val <= unorder_head->val; p = p->next);
            ListNode* tmp = unorder_head;
            unorder_head = unorder_head->next;
            tmp->next = p->next;
            p->next = tmp;
        }
        return head;
    }
};
