// 84ms O(log(n)) solution: T(n) = O(log(n)) + T(n/2)
// by hxdone

#include<iostream>
#include<cmath>
using namespace std;

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode* leftmost = root;
        int h = 1;
        while (leftmost->left) {
            leftmost = leftmost->left;
            ++h;
        }
        TreeNode* rmol = root->left; // reach rightmost of left
        int h_left = 0;
        while (rmol) {
            rmol = rmol->right;
            h_left++;
        }
        if (h_left == h-1) // left is full
            return pow(2, h-1) + countNodes(root->right);
        else // left is not full
            return pow(2, h-2) + countNodes(root->left);
    }
};

int main () {
    Solution s;

    TreeNode* root = NULL;
    cout << "case 1: " << s.countNodes(root) << endl;

    root = new TreeNode(1);
    cout << "case 2: " << s.countNodes(root) << endl;

    root->left = new TreeNode(2);
    cout << "case 3: " << s.countNodes(root) << endl;

    root->right = new TreeNode(3);
    cout << "case 4: " << s.countNodes(root) << endl;

    root->left->left = new TreeNode(4);
    cout << "case 5: " << s.countNodes(root) << endl;
    
    root->left->right = new TreeNode(5);
    cout << "case 6: " << s.countNodes(root) << endl;
    
    root->right->left = new TreeNode(6);
    cout << "case 7: " << s.countNodes(root) << endl;

    root->right->right = new TreeNode(7);
    cout << "case 8: " << s.countNodes(root) << endl;
}
