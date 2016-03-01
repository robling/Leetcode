#include "../include/pre.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* invertTree(TreeNode* root)
{
    if (root == NULL) retutn NULL;
    auto tmp = root->right;
    root->right = invertTree(root->left);
    root->left = invertTree(tmp);
    return root;
}

int main()
{
    return 0;
}