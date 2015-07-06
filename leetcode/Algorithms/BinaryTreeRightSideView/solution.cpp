// right-to-left preorder traverse of binary tree
// recursion solution by hxdone

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        rightSideView(root, 0, ret);
        return ret;
    }
private: 
    void rightSideView(TreeNode* root, int depth, vector<int>& cur_result) {
        if (!root) return;
        if (depth >= cur_result.size())
            cur_result.push_back(root->val);
        rightSideView(root->right, depth+1, cur_result);
        rightSideView(root->left, depth+1, cur_result);
    }
};
