/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<TreeNode*> TreeList;//定义一个数组，根据中序遍历来存储结点。

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        TreeList.push_back(root);
        inorder(root->right);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) return pRootOfTree;
        inorder(pRootOfTree);
        for (int i = 0; i < TreeList.size() - 1; i++) { //根据数组中的顺序将结点连接，注意i的范围。
            TreeList[i]->right = TreeList[i + 1];
            TreeList[i + 1]->left = TreeList[i];
        }
        return TreeList[0];//数组的头部存储的是双向链表的第一个结点。
    }
};