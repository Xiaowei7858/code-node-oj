* Definition for a binary tree node.
* struct TreeNode {
    *int val;
    *TreeNode* left;
    *TreeNode* right;
    *TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    *
};
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root = nullptr;
        if (!t1 && !t2) return root;
        if (t1 || t2) {
            int value = 0;
            if (t1 && t2)
                value = t1->val + t2->val;
            else
                value = t1 == nullptr ? t2->val : t1->val;
            root = new TreeNode(value);
            root->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
            root->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        }
        return root;
    }
};