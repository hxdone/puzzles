// by hxdone

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
		ListNode* ret_head = NULL;
		while (head) {
			cur = head;
			head = head->next;
			cur->next = ret_head;
			ret_head = cur;
		}
		return ret_head;
	}
};
