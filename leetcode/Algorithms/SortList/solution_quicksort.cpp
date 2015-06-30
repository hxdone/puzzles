// by hxdone

#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list. */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
		cout << "sortList head:" << head << endl;
        if (!head || head->next == NULL)
            return head;
        ListNode* prev_pivot = partition(head, &head);
		cout << "partion_result:" << prev_pivot << endl;
		cout << "head after partion:" << head << endl;
        if (prev_pivot == NULL) {
			cout << "head:" << head << endl;
            head->next = sortList(head->next);
            return head;
        }
        ListNode* pivot = prev_pivot->next;
        prev_pivot->next = NULL;
        head = sortList(head);
        for (prev_pivot = head; prev_pivot->next != NULL; prev_pivot = prev_pivot->next);
        prev_pivot->next = pivot;
        pivot->next = sortList(pivot->next);
        return head;
    }
private:
    ListNode* partition(ListNode* head, ListNode** new_head) {
        if (!head || head->next == NULL) {
            *new_head = head;
            return NULL;
        }
        ListNode* smaller_head = NULL;
        ListNode* smaller_tail = NULL;
        ListNode* cur = head->next;
        ListNode* no_smaller_tail = head;
        no_smaller_tail->next = NULL;
        while (cur != NULL) {
            if (cur->val < head->val) {
                if (smaller_head == NULL) {
                    smaller_head = cur;
                    smaller_tail = cur;
                } else {
                    smaller_tail->next = cur;
                    smaller_tail = cur;
                }
                cur = cur->next;
                smaller_tail->next = NULL;
            } else {
                no_smaller_tail->next = cur;
                no_smaller_tail = cur;
                cur = cur->next;
                no_smaller_tail->next = NULL;
            }
        }
        if (smaller_head != NULL) {
            smaller_tail->next = head;
			*new_head = smaller_head;
		} else
			*new_head = head;
        return smaller_tail;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	cout << "before sort:" <<  head << ", " << head->next << ", "<< head->next->next <<", " << head->next->next->next << ", " << head->next->next->next->next <<endl;
	Solution s;
	ListNode* tmp = s.sortList(head);
	while(tmp) {
		cout << tmp->val <<endl;
		tmp = tmp->next;
	}
	return 0; 
}
