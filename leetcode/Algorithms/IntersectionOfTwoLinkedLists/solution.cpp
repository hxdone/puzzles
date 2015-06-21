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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0, n = 0;
        for(ListNode* p = headA; p; p=p->next, ++m);
        for(ListNode* p = headB; p; p=p->next, ++n);
        while (m>0 && n>0) {
            if(m>n) {
                headA = headA->next;
                --m;
            } else if (m<n) {
                headB = headB->next;
                --n;
            } else {
                if (headA == headB) return headA;
                else {
                    headA = headA->next;
                    headB = headB->next;
                    --m;
                    --n;
                }
            }
        }
        return NULL;
    }
};
