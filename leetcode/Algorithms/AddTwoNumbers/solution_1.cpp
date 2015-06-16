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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = NULL;
		ListNode* tail = NULL;
		int extra = 0;
		while (l1 || l2) {
			auto l1_val = l1 ? l1->val : 0;
			auto l2_val = l2 ? l2->val : 0;
			auto remainder = (l1_val + l2_val + extra) % 10;
			extra = (l1_val + l2_val + extra) / 10;
			auto tmp = new ListNode(remainder);
			if (!head)
				head = tmp;
			else
				tail->next = tmp;
			tail = tmp;
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;
		}
		if (extra > 0)
			tail->next = new ListNode(extra);
		return head;
	}
};
