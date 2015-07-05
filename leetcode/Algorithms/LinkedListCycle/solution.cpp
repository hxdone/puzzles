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
    bool hasCycle(ListNode *head) {
        if (!head || head->next == NULL)
            return false;
        ListNode* one_step_pointer = head;
        ListNode* two_step_pointer = head->next;
        while (one_step_pointer && two_step_pointer && one_step_pointer != two_step_pointer) {
            one_step_pointer = one_step_pointer->next;
            two_step_pointer = two_step_pointer->next; 
            if (two_step_pointer)
                two_step_pointer = two_step_pointer->next;
            else
                return false;
        }
        return one_step_pointer && two_step_pointer;
    }
};
