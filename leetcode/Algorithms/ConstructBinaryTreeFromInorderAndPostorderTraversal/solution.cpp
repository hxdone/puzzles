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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
private:
    TreeNode* buildTree(vector<int>& inorder, int in_start,  int in_end, vector<int>& postorder, int po_start, int po_end) {
        if (in_end < in_start)
            return NULL;
        TreeNode* root = new TreeNode(postorder[po_end]);
        int i = in_start;
        while (i <= in_end && inorder[i] != postorder[po_end])
            ++i;
        root->left = buildTree(inorder, in_start, i-1, postorder, po_start, po_start+i-1-in_start);
        root->right = buildTree(inorder, i+1, in_end, postorder, po_start+i-in_start, po_end-1);
        return root;
    }
};
