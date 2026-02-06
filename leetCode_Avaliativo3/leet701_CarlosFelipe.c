// Carlos Felipe Pereira Bellomo M2 - leet 701

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *insertIntoBST(struct TreeNode *root, int val);

// Cria um novo nó
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Imprime a árvore em ordem para conferir o resultado
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

    int val = 5;
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

       root = insertIntoBST(root, val);

    printf("Inorder invertida: ");
    printInorder(root);
    printf("\n");

    return 0;
}

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{

    if (root == NULL)
    {
        struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}