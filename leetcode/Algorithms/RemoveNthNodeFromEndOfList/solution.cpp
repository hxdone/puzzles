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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* tail = head;
		for (int i = 1 ; i < n; ++i)
			tail = tail->next;
		if (tail->next == NULL) {
			ListNode* tmp = head;
			head = head->next;
			delete tmp;
			return head;
		}
		tail = tail->next;
		ListNode* prev = head;
		while (tail->next) {
			tail = tail->next;
			prev = prev->next;
		}
		ListNode* tmp = prev->next;
		prev->next = tmp->next;
		delete tmp;
		return head;
	}
};
