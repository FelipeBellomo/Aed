#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int helper(struct TreeNode *root);
bool isBalanced(struct TreeNode *root);

// Cria um novo nó
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Imprime a árvore em ordem (Inorder) para conferir o resultado
void printInorder(struct TreeNode *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->val);
    printInorder(node->right);
}

int main()
{

    struct TreeNode *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);

    bool resp = isBalanced(root);

    if (resp)
        printf("true");
    else
        printf("false");

    return 0;
}

int helper(struct TreeNode *root)
{

    if (root == NULL)
        return 0;

    int left = helper(root->left);
    int right = helper(root->right);

    return (left > right ? left : right) + 1;
}

bool isBalanced(struct TreeNode *root)
{
    if (root == NULL)
        return true;

    int leftH = helper(root->left);
    int rightH = helper(root->right);

    if (abs(leftH - rightH) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}