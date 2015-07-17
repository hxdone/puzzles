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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ancestors_p, ancestors_q;
        
        // preorder traverse of the tree to find p and q, and keep the ancestor nodes
        findNodeInTree(root, p, ancestors_p);
        findNodeInTree(root, q, ancestors_q);
        
        // find the longest common prefix
        while (true) {
            if (ancestors_p.size() > ancestors_q.size()) {
                ancestors_p.pop();
            } else if (ancestors_p.size() < ancestors_q.size()) {
                ancestors_q.pop();
            } else {
                if (ancestors_p.top() == ancestors_q.top()) {
                    return ancestors_p.top();
                } else {
                    ancestors_p.pop();
                    ancestors_q.pop();
                }
            }
        }
        return NULL;
    }
private:
    bool findNodeInTree(TreeNode* root, TreeNode* p, stack<TreeNode*>& ancestors) {
        if (!root)
            return false;
        ancestors.push(root);
        if (root == p || findNodeInTree(root->left, p, ancestors) || findNodeInTree(root->right, p, ancestors))
            return true;
        else {
            ancestors.pop();
            return false;
        }
    }
};
