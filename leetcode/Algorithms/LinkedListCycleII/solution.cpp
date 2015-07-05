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
    ListNode *detectCycle(ListNode *head) {
        if (!head || head->next == NULL)
            return NULL;
        
        // find a node in cycle
        ListNode* one_stepper = head;
        ListNode* two_stepper = head->next;
        while (one_stepper && two_stepper && one_stepper != two_stepper) {
            one_stepper = one_stepper->next;
            two_stepper = two_stepper->next;
            if (two_stepper)
                two_stepper = two_stepper->next;
            else
                return NULL;
        }
        if (!one_stepper || !two_stepper)
            return NULL;
        
        // count the length of the cycle
        one_stepper = one_stepper->next;
        int len = 1;
        while (one_stepper != two_stepper) {
            ++len;
            one_stepper = one_stepper->next;
        }
        
        //find the enter node of cycle
        one_stepper = head;
        two_stepper = head;
        for (int i = 0; i < len; ++i)
            two_stepper = two_stepper->next;
        while (one_stepper != two_stepper){
            one_stepper = one_stepper->next;
            two_stepper = two_stepper->next;
        }
        return one_stepper;
    }
};
