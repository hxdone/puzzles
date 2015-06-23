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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        else return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        else if (!t1 || !t2) return false;
        else return (t1->val == t2->val) && isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
    }
};
