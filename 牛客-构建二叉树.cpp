
#include<stdio.h>

typedef struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* CreateTree(char* str, int* pi) {
    if (str[*pi] == '#') {
        ++(*pi);
        return NULL;
    }
    else {
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->val = str[*pi];
        (*pi)++;
        root->left = CreateTree(str, pi);
        root->right = CreateTree(str, pi);

        return root;
    }
}

void Inorder(TreeNode* root) {
    if (!root)
        return;

    Inorder(root->left);
    printf("%c ", root->val);
    Inorder(root->right);
}
int main() {
    char str[100];
    scanf("%s", str);

    int i = 0;
    TreeNode* root = CreateTree(str, &i);

    Inorder(root);
    return 0;
}