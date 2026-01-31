/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode *root)
{
    int left = 0;
    int right = 0;

    if (root == NULL)
        return 0;

    left = maxDepth(root->left);
    right = maxDepth(root->right);

    return (left > right ? left : right) + 1;
}