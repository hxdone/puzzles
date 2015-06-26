// Morris Preorder Traversal
// by hxdone

#include <vector>
#include <iostream>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        while (root != NULL) {
            if (root->left != NULL) {
                TreeNode* rightmost_of_left = root->left;
                while (rightmost_of_left->right != NULL && rightmost_of_left->right != root)
                    rightmost_of_left = rightmost_of_left->right;
				if (rightmost_of_left->right == NULL) {
					ret.push_back(root->val);
                	rightmost_of_left->right = root;
					root = root->left;
				} else {
					rightmost_of_left->right = NULL;
					root = root->right;
				}
            } else {
            	ret.push_back(root->val);
                root = root->right;
            }
        }
        return ret;
    }
};

int main() {
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->left->right = new TreeNode(2);

	Solution s;
	vector<int> path = s.preorderTraversal(root);
	for (int i = 0; i < path.size(); ++i) {
		cout << path[i] <<endl;
	}
	// delete the tree
}
