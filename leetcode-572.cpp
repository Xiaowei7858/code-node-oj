/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool issame(TreeNode* _s, TreeNode* _t) {
        if (!_s && !_t)
            return true;

        if (!_s || !_t)
            return false;

        if (_s->val != _t->val)
            return false;

        return issame(_s->left, _t->left) && issame(_s->right, _t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s)
            return false;

        if (issame(s, t))
            return true;

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};