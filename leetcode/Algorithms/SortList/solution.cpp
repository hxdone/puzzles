// merge sort of linked list
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
    ListNode* sortList(ListNode* head) {
        if (!head || head->next == NULL)
            return head;
        ListNode* head1 = head;
        ListNode* tail1 = head;
        ListNode* head2 = head->next;
        ListNode* tail2 = head->next;
        head = head2->next;
        tail1->next = NULL;
        tail2->next = NULL;
        for (int cnt = 0; head != NULL; ++cnt) {
            if (cnt % 2 == 0) {//insert list 1
                tail1->next = head;
                head = head->next;
                tail1 = tail1->next;
                tail1->next = NULL;
            } else {
                tail2->next = head;
                head = head->next;
                tail2 = tail2->next;
                tail2->next = NULL;
            }
        }
        head1 = sortList(head1);
        head2 = sortList(head2);
        return merge(head1, head2);
    }
private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                if (head == NULL)
                    head = head1;
                else
                    tail->next = head1;
                tail = head1;
                head1 = head1->next;
            } else {
                if (head == NULL)
                    head = head2;
                else
                    tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
            tail->next = NULL;
        }
        if (head1) {
            if (head != NULL)
                tail->next = head1;
            else
                head = head1;
        } else if (head2) {
            if (head != NULL)
                tail->next = head2;
            else
                head = head2;
        }
        return head;
    }
};

