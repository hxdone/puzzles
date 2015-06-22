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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode* last = head;
        while (last->next) {
            ListNode* p = last->next;
            if (p->val == last->val) {
                last->next = p->next;
                delete p;
            } else
                last = last->next;
        }
        return head;
    }
};
