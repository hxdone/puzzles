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
	ListNode* removeElements(ListNode* head, int val) {
		while (head && head->val == val) {
			ListNode * tmp = head;
			head = head->next;
			delete tmp;
		}
		ListNode* prev = head;
		while (prev) {
			ListNode* cur = prev->next;
			while (cur && cur->val == val) {
				prev->next = cur->next;
				delete cur;
				cur = prev->next;
			}
			prev = prev->next;
		}
		return head;
	}
};
