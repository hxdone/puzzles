// by hxdone

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode* t = root;
        while (t && t->left) {
            s.push(t);
            t = t->left;
        }
        cur = t;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int ret = 0;
        if (cur)
            ret = cur->val;
        if (cur->right) {
            TreeNode* t = cur->right;
            while (t->left) {
                s.push(t);
                t = t->left;
            }
            cur = t;
        } else if (!s.empty()){
            cur = s.top();
            s.pop();
        } else
            cur = NULL;
        return ret;
    }
private:
    stack<TreeNode*> s;
    TreeNode* cur;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
