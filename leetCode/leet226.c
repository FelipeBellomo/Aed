#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode *invertTree(struct TreeNode *root);

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

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

    printf("Inorder original: ");
    printInorder(root);
    printf("\n");

    // Chama a função do desafio
    root = invertTree(root);

    printf("Inorder invertida: ");
    printInorder(root);
    printf("\n");

    return 0;
}

struct TreeNode *invertTree(struct TreeNode *root)
{
    struct TreeNode *sup;

    if (root != NULL)
    {

        sup = root->left;
        root->left = root->right;
        root->right = sup;

        invertTree(root->left);
        invertTree(root->right);
    }
    else
        return NULL;

    return root;
}