// by hxdone

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        else if (head->next == NULL) return new TreeNode(head->val);
        // get the length of the list
        ListNode* p = head;
        int length = 0;
        while (p) {
            p = p->next;
            ++length;
        }
        // split the list from the middle, and do recursion
        int left_len = length/2;
        ListNode* left_tail = head;
        for (int i = 1; i < left_len; ++i)
            left_tail = left_tail->next;
        TreeNode* root = new  TreeNode(left_tail->next->val);
        ListNode* root_node = left_tail->next;
        left_tail->next = NULL;
        root->left = sortedListToBST(head);
        left_tail->next = root_node;
        root->right = sortedListToBST(root_node->next);
        return root;
    }
};
