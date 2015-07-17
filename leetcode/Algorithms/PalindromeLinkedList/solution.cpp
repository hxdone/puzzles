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
    bool isPalindrome(ListNode* head) {
        if (!head || head->next == NULL)
            return true;
        ListNode* p = head;
        int len = 0;
        while (p) {
            ++len;
            p = p->next;
        }
        //reverse the second half
        ListNode* half_tail = head;
        for (int i = 1; i < len/2; ++i)
            half_tail = half_tail->next;
        ListNode* second_half_head = reverse(half_tail->next);
        half_tail->next = NULL;
        bool ret = true;
        
        p = head;
        ListNode* q = second_half_head;
        while (p && q) {
            if (p->val != q->val) {
                ret = false;
                break;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        half_tail->next = reverse(second_half_head);
        return ret;
    }
private:
    ListNode* reverse(ListNode* head) {
        if (!head || head->next == NULL)
            return head;
        ListNode* new_head = head;
        ListNode* old_list = head->next;
        new_head->next = NULL;
        while (old_list) {
            ListNode* tmp = old_list;
            old_list = old_list->next;
            tmp->next = new_head;
            new_head = tmp;
        }
        return new_head;
    }
};
