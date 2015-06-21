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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *tail = NULL;
        if(!l1) return l2;
        else if (!l2) return l1;
        else {
            if (l1->val <= l2->val) {
                head = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                head = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1:l2;
        return head;
    }
};
