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
    bool isequal(TreeNode* root, int cur_val) {
        if (!root) return true;
        if ((root->val ^ cur_val) != 0)
            return false;

        return isequal(root->left, cur_val) && isequal(root->right, cur_val);
    }
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        int cur_val = root->val;
        return isequal(root, cur_val);
    }
};