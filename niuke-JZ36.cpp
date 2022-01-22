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
    vector<TreeNode*> TreeList;//����һ�����飬��������������洢��㡣

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        TreeList.push_back(root);
        inorder(root->right);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) return pRootOfTree;
        inorder(pRootOfTree);
        for (int i = 0; i < TreeList.size() - 1; i++) { //���������е�˳�򽫽�����ӣ�ע��i�ķ�Χ��
            TreeList[i]->right = TreeList[i + 1];
            TreeList[i + 1]->left = TreeList[i];
        }
        return TreeList[0];//�����ͷ���洢����˫������ĵ�һ����㡣
    }
};