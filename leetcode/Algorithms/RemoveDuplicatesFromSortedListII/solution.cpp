// recursion solution by hxdone

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
        if (!head || head->next == NULL) return head;
        while (head && head->next && head->next->val == head->val) {
            // should delete heading elements
            ListNode* p = head->next->next;
            int val = head->val;
            delete head;
            delete head->next;
            while (p && p->val == val) {
                ListNode* tmp = p;
                p = p->next;
                delete tmp;
            }
            head = p;
        }
        if (head)
            head->next = deleteDuplicates(head->next);
        return head;
    }
};
