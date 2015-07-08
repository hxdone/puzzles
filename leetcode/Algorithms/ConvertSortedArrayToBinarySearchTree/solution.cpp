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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start_idx, int end_idx) {
        if (start_idx > end_idx)
            return NULL;
        int mid_idx = (start_idx+end_idx)/2;
        TreeNode* root = new TreeNode(nums[mid_idx]);
        root->left = sortedArrayToBST(nums, start_idx, mid_idx-1);
        root->right = sortedArrayToBST(nums, mid_idx+1, end_idx);
        return root;
    }
};
