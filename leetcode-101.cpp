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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return cmp(root, root);
    }

    bool cmp(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;

        if (!p || !q)
            return false;

        if (p->val == q->val)
            return cmp(p->left, q->right) && cmp(p->right, q->left);

        return false;
    }
};