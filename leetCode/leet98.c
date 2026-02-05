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

bool isValidBST(struct TreeNode *root);

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
    struct TreeNode *root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(6);
    root->right->right = newNode(9);

    printf("Inorder original: ");
    printInorder(root);
    printf("\n");

    // Chama a função do desafio
    bool anwser = isValidBST(root);

    if (anwser)
    {
        printf("true ");
        printf("\n");
    }
    else
    {
        printf("false");
    }

    return 0;
}

bool isValidBST(struct TreeNode *root)
{

    if (root == NULL)
        return true;

    if (root->left->val < root->val && root->val < root->right->val)
    {
        return isValidBST(root->left);

        //       isValidBST(root->right);
    }
    else
    {
        return false;
    }

    return true;
}