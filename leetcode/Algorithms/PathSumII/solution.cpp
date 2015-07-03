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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> cur_path;
        pathSum(root, sum, cur_path, ret);
        return ret;
    }
private:
    void pathSum(TreeNode* root, int sum, vector<int>& cur_path, vector<vector<int>>& ret) {
        if (!root) return;
        else if (root->left != NULL || root->right!= NULL){
            cur_path.push_back(root->val);
            pathSum(root->left, sum-root->val, cur_path, ret);
            pathSum(root->right, sum-root->val, cur_path, ret);
            cur_path.pop_back();
        } else {
            if(sum == root->val) {
                cur_path.push_back(root->val);
                ret.push_back(cur_path);
                cur_path.pop_back();
            }
        }
    }
};
