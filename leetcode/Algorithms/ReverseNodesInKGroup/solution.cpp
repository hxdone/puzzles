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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        int i = 0;
        while (p && i < k-1) {
            ++i;
            p = p->next;
        }
        if (!p) return head;
        else {
            ListNode* remain = p->next;
            p->next = NULL;
            ListNode* new_head = reverseList(head);
            head->next = reverseKGroup(remain, k);
            return new_head;
        }
    }
private:
    ListNode* reverseList(ListNode* head) {
        if (!head || head->next == NULL) return head;
        ListNode* new_head = head;
        ListNode* remain = head->next;
        new_head->next = NULL;
        while (remain) {
            ListNode* tmp = remain;
            remain = remain->next;
            tmp->next = new_head;
            new_head = tmp;
        }
    }
};
