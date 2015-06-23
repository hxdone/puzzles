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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vals;
        if (!root) return vals;
        queue<TreeNode*> nodes;
        queue<int> levels;
        nodes.push(root);
        levels.push(0);
        int cur_level = -1;
        while(!nodes.empty()) {
            TreeNode* t = nodes.front();
            if (levels.front() != cur_level) {
                vals.push_back(vector<int>());
                ++cur_level;
            }
            if (t->left) {
                nodes.push(t->left);
                levels.push(cur_level+1);
            }
            if (t->right) {
                nodes.push(t->right);
                levels.push(cur_level+1);
            }
            vals[cur_level].push_back(t->val);
            nodes.pop();
            levels.pop();
        }
		
		// the only diff with BinaryTreeLevelOrderTraversal solution is below
        for (int i = 0; i < vals.size()/2; ++i)
            vals[i].swap(vals[vals.size()-1-i]);

        return vals;
    }
};
