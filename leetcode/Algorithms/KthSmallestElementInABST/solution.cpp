// stack-based inorder tranverse
// by hxdone

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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* p = root;
        stack<TreeNode*> s;
        while (p || !s.empty()) {
            if (!p) {
                p = s.top();
                s.pop();
                if (--k == 0)
                    return p->val;
                p = p->right;
            } else if (p->left){
                s.push(p);
                p = p->left;
            } else {
                if (--k == 0)
                    return p->val;
                p = p->right;
            }
        }
        return 0;
    }
};
