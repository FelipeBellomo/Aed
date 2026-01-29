/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sup(struct TreeNode *root, int *returnSize, int *answer)
{

    if (root == NULL)
        return;

    answer[(*returnSize)] = root->val;

    (*returnSize)++;

    sup(root->left, returnSize, answer);
    sup(root->right, returnSize, answer);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{

    int *answer = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;

    sup(root, returnSize, answer);

    return answer;
}