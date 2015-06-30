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
    void reorderList(ListNode* head) {
        if (!head || head->next == NULL)
            return;
        int cnt = 0;
        for (ListNode* p = head; p != NULL; p = p->next)
            ++cnt;
        ListNode* p = head;
        for (int i = 1; i < (cnt+1)/2; ++i)
            p = p->next;
        ListNode* head2 = p->next;
        p->next = NULL;
        head2 = reverseList(head2);
        ListNode* tail = head;
        ListNode* head1 = head->next;
        tail->next = NULL;
        for (int i = 1; i < cnt; ++i) {
            if (i % 2) {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            } else {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            }
            tail->next = NULL;
        }
    }
private:
    ListNode* reverseList(ListNode* head) {
        if (!head || head->next == NULL) return head;
        ListNode* new_head = head;
        head = head->next;
        new_head->next = NULL;
        while (head != NULL) {
            ListNode* cur = head;
            head = head->next;
            cur->next = new_head;
            new_head = cur;
        }
        return new_head;
    }
};
