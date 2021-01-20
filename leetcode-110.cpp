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
    /*  //ǰ�� ʱ�临�Ӷ�O��N^2��
        //����߶�
        int depthTree(TreeNode* root){
            if(!root)
            return 0;

            int left = depthTree(root->left);
            int right = depthTree(root->right);

            return left > right ? left + 1 : right + 1;
        }
        //�ж�
        bool isBalanced(TreeNode* root) {
            if(!root) return true;

            int depth = 0;
            int left = depthTree(root->left);
            int right = depthTree(root->right);

            return abs(left - right) < 2 && isBalanced(root->left) && isBalanced(root->right);
        }
        */
        //�������
    bool _isBlalaced(TreeNode* root, int* pDepth) {
        if (!root) {
            *pDepth = 0;
            return true;
        }

        int leftdepth = 0;
        if (!_isBlalaced(root->left, &leftdepth))
            return false;

        int rightdepth = 0;
        if (!_isBlalaced(root->right, &rightdepth))
            return false;

        if (abs(leftdepth - rightdepth) > 1)
            return false;

        *pDepth = leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        int depth = 0;
        return _isBlalaced(root, &depth);
    }
};