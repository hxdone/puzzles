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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        else if (root->left == NULL && root->right == NULL) // leaf
            return root->val == sum;
        else // non-leaf
            return (hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val));
    }
};
